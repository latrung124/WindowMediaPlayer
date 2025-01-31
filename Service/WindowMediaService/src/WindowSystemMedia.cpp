/*
* File: WindowSystemMedia.cpp
* Author: trung.la
* Date: 01-09-2025
* Description: Implementation of window system media
*/

#include "WindowMediaService.h"
#include "WindowSystemMedia.h"

#include <iostream>
#include <fstream>
#include <filesystem>
#include <random>

#include <winrt/Windows.Storage.Streams.h>
#include <winrt/Windows.Foundation.h>

namespace {

using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::Media::Control;
using namespace Windows::Storage;
using namespace Windows::Storage::Streams;
using namespace WindowServiceUtils;

static WMediaPlaybackType convertPlaybackType(Windows::Foundation::IReference<Windows::Media::MediaPlaybackType> playbackType) {
    if (playbackType == nullptr) {
        return WMediaPlaybackType::Unknown;
    }

    const auto playbackTypeValue = playbackType.Value();
    switch (playbackTypeValue) {
    case Windows::Media::MediaPlaybackType::Music:
        return WMediaPlaybackType::Music;
    case Windows::Media::MediaPlaybackType::Video:
        return WMediaPlaybackType::Video;
    case Windows::Media::MediaPlaybackType::Image:
        return WMediaPlaybackType::Image;
    default:
        return WMediaPlaybackType::Unknown;
    }
}

int generateRandom7DigitNumber() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1000000, 9999999);  // Range for a 7-digit number

    return dist(gen);
}

std::string saveThumbnailToFile(const GlobalSystemMediaTransportControlsSessionMediaProperties& mediaProperties) {
    try {
        auto thumbnailReference = mediaProperties.Thumbnail();
        if (!thumbnailReference) {
            std::wcerr << L"No thumbnail available." << std::endl;
            return "";
        }

        auto stream = thumbnailReference.OpenReadAsync().get();
        if (!stream) {
            std::wcerr << L"Failed to open thumbnail stream." << std::endl;
            return "";
        }

        auto temporaryFileName = std::to_string(generateRandom7DigitNumber()) + "_thumbnail.jpg";
        auto outputPath = std::filesystem::temp_directory_path().append(temporaryFileName).string();
        auto size = static_cast<size_t>(stream.Size());
        std::vector<uint8_t> buffer(size);

        auto reader = DataReader(stream);
        reader.LoadAsync(static_cast<uint32_t>(size)).get();
        reader.ReadBytes(buffer);

        std::ofstream outputFile(outputPath, std::ios::binary);
        if (outputFile.is_open()) {
            outputFile.write(reinterpret_cast<const char*>(buffer.data()), buffer.size());
            outputFile.close();
            std::cout << "Thumbnail saved to: " << outputPath << std::endl;
            return outputPath;
        } else {
            std::wcerr << L"Failed to open output file." << std::endl;
            return "";
        }
    } catch (const hresult_error& ex) {
        std::wcerr << L"Error: " << ex.message().c_str() << std::endl;
        return "";
    }
}

std::chrono::system_clock::time_point convertDateTimeToChrono(DateTime winrtTime) {
    // Duration since January 1, 1601 (UTC) in 100-nanosecond units
    auto duration100ns = std::chrono::duration<int64_t, std::ratio<1, 10'000'000>>(winrtTime.time_since_epoch().count());

    // Windows epoch start (January 1, 1601) as a chrono time_point
    constexpr std::chrono::system_clock::time_point windowsEpoch = std::chrono::system_clock::time_point(std::chrono::duration<int64_t>(11644473600)); // seconds from 1601 to 1970

    // Convert to standard system_clock time_point
    return windowsEpoch + duration100ns;
}

} // namespace

WindowSystemMedia::WindowSystemMedia(WindowSystemMedia &&service) noexcept
{
    m_service = service.m_service;
    service.m_service = nullptr;
    m_sessionManager = GlobalSystemMediaTransportControlsSessionManager(service.m_sessionManager);
    service.m_sessionManager = nullptr;
    m_session = GlobalSystemMediaTransportControlsSession(service.m_session);
    service.m_session = nullptr;
    m_sessionChangedToken = service.m_sessionChangedToken;
    m_mediaPropertiesToken = service.m_mediaPropertiesToken;
    m_playbackInfoToken = service.m_playbackInfoToken;
}

WindowSystemMedia& WindowSystemMedia::operator=(WindowSystemMedia &&service) noexcept
{
    m_service = service.m_service;
    m_sessionManager = GlobalSystemMediaTransportControlsSessionManager(service.m_sessionManager);
    service.m_sessionManager = nullptr;
    m_session = GlobalSystemMediaTransportControlsSession(service.m_session);
    service.m_session = nullptr;
    m_sessionChangedToken = std::move(service.m_sessionChangedToken);
    m_mediaPropertiesToken = std::move(service.m_mediaPropertiesToken);
    m_playbackInfoToken = std::move(service.m_playbackInfoToken);

    return *this;
}

WindowSystemMedia::WindowSystemMedia(WindowMediaService* service)
    : m_service(service)
{
    systemInit();
}

bool WindowSystemMedia::systemInit()
{
    try {
        IAsyncOperation<GlobalSystemMediaTransportControlsSessionManager>
            sessionManagerRes = GlobalSystemMediaTransportControlsSessionManager::RequestAsync();
        m_sessionManager = sessionManagerRes.get();
        if (!m_sessionManager) {
            return false;
        }
        registerCurrentSessionChangedEvents();

        m_session = m_sessionManager.GetCurrentSession();
        if (m_session) {
            registerSessionPropertiesChangedEvents();
        }
    } catch(winrt::hresult_error const& ex) {
        winrt::hstring message = ex.message();
        throw std::runtime_error(winrt::to_string(message));
    }
    catch (...) {
        throw std::runtime_error("Unknown error");
    }

    return true;
}

void WindowSystemMedia::registerCurrentSessionChangedEvents()
{
    if (m_sessionManager) {
        m_sessionChangedToken = m_sessionManager.CurrentSessionChanged([this](GlobalSystemMediaTransportControlsSessionManager manager,
                                                                         CurrentSessionChangedEventArgs args) {
            registerSessionPropertiesChangedEvents();
        });
    }
}

void WindowSystemMedia::registerSessionPropertiesChangedEvents()
{
    if (!m_session) {
        return;
    }

    m_mediaPropertiesToken = m_session.MediaPropertiesChanged([this](GlobalSystemMediaTransportControlsSession session, MediaPropertiesChangedEventArgs args) {
        //TODO: handle media properties changed
        const auto mediaPropertiesAsync = session.TryGetMediaPropertiesAsync();
        const auto mediaProperties = mediaPropertiesAsync.get();

        removeOldTempThumbnail();

        WMediaInfo mediaInfo{
            .albumTitle = winrt::to_string(mediaProperties.AlbumTitle()),
            .albumArtist = winrt::to_string(mediaProperties.AlbumArtist()),
            .totalTracks = mediaProperties.AlbumTrackCount(),
            .artist = winrt::to_string(mediaProperties.AlbumArtist()),
            .genres = {}, // TODO: handle genres data
            .playbackType = convertPlaybackType(mediaProperties.PlaybackType()),
            .subtitle = winrt::to_string(mediaProperties.Subtitle()),
            .thumbnail = saveThumbnailToFile(mediaProperties),
            .title = winrt::to_string(mediaProperties.Title()),
            .trackNumber = mediaProperties.TrackNumber(),
        };
        m_thumbnailPath = mediaInfo.thumbnail;
        m_service->systemMediaPropertiesChanged(mediaInfo);
    });

    m_playbackInfoToken = m_session.PlaybackInfoChanged([this](GlobalSystemMediaTransportControlsSession session, PlaybackInfoChangedEventArgs args) {
        auto playbackInfo = session.GetPlaybackInfo();
        auto playbackControls = playbackInfo.Controls();
        auto playbackStatus = playbackInfo.PlaybackStatus();
        auto playbackType = playbackInfo.PlaybackType();
        auto repeatMode = playbackInfo.AutoRepeatMode();

        if (!playbackControls) {
            return;
        }

        WPlaybackControls wPlaybackControls{
            .isChannelDownEnabled = playbackControls.IsChannelDownEnabled(),
            .isChannelUpEnabled = playbackControls.IsChannelUpEnabled(),
            .isFastForwardEnabled = playbackControls.IsFastForwardEnabled(),
            .isNextEnabled = playbackControls.IsNextEnabled(),
            .isPauseEnabled = playbackControls.IsPauseEnabled(),
            .isPlaybackPositionEnabled = playbackControls.IsPlaybackPositionEnabled(),
            .isPlaybackRateEnabled = playbackControls.IsPlaybackRateEnabled(),
            .isPlayEnabled = playbackControls.IsPlayEnabled(),
            .isPlayPauseToggleEnabled = playbackControls.IsPlayPauseToggleEnabled(),
            .isPreviousEnabled = playbackControls.IsPreviousEnabled(),
            .isRecordEnabled = playbackControls.IsRecordEnabled(),
            .isRepeatEnabled = playbackControls.IsRepeatEnabled(),
            .isRewindEnabled = playbackControls.IsRewindEnabled(),
            .isShuffleEnabled = playbackControls.IsShuffleEnabled(),
            .isStopEnabled = playbackControls.IsStopEnabled(),
        };

        WMediaPlaybackAutoRepeatMode wRepeatMode = repeatMode == nullptr ? WMediaPlaybackAutoRepeatMode::None : static_cast<WMediaPlaybackAutoRepeatMode>(repeatMode.Value());
        WMediaPlaybackStatus wPlaybackStatus = static_cast<WMediaPlaybackStatus>(playbackStatus);
        WMediaPlaybackType wPlaybackType = convertPlaybackType(playbackType);

        bool isShuffled = false;
        if (playbackInfo.IsShuffleActive()) {
            isShuffled = playbackInfo.IsShuffleActive().Value();
        }
        double playbackRate = 0.0;
        if (playbackInfo.PlaybackRate()) {
            playbackRate = playbackInfo.PlaybackRate().Value();
        }
        WPlaybackInfo wPlaybackInfo{
            .autoRepeatMode = wRepeatMode,
            .playbackControls = wPlaybackControls,
            .isShuffled = isShuffled,
            .playbackRate = playbackRate,
            .playbackStatus = wPlaybackStatus,
            .playbackType = wPlaybackType,
       };

        m_service->systemPlaybackInfoChanged(wPlaybackInfo);
    });

    m_timelinePropertiesToken = m_session.TimelinePropertiesChanged([this](GlobalSystemMediaTransportControlsSession session, TimelinePropertiesChangedEventArgs args) {
        const auto timelineProperties = session.GetTimelineProperties();
        if (!timelineProperties) {
            return;
        }

        WTimelineProperties wTimelineProperties{
            .endTime = timelineProperties.EndTime().count(),
            .startTime = timelineProperties.StartTime().count(),
            .lastUpdatedTime = convertDateTimeToChrono(timelineProperties.LastUpdatedTime()),
            .maxSeekTime = timelineProperties.MaxSeekTime().count(),
            .minSeekTime = timelineProperties.MinSeekTime().count(),
            .position = timelineProperties.Position().count(),
        };

        // m_service->systemTimelinePropertiesChanged(wTimelineProperties);
    });
}

void WindowSystemMedia::removeOldTempThumbnail()
{
    if (!m_thumbnailPath.empty()) {
        std::filesystem::remove(m_thumbnailPath);
    }
}
