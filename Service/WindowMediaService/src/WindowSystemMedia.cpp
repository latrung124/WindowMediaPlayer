/*
* File: WindowSystemMedia.cpp
* Author: trung.la
* Date: 01-09-2025
* Description: Implementation of window system media
*/

#include "WindowMediaService.h"
#include "WindowSystemMedia.h"

#include <winrt/Windows.Foundation.h>

namespace {

using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::Media::Control;
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

        WMediaInfo mediaInfo{
            .albumTitle = winrt::to_string(mediaProperties.AlbumTitle()),
            .albumArtist = winrt::to_string(mediaProperties.AlbumArtist()),
            .totalTracks = mediaProperties.AlbumTrackCount(),
            .artist = winrt::to_string(mediaProperties.AlbumArtist()),
            .genres = {}, // TODO: handle genres data
            .playbackType = convertPlaybackType(mediaProperties.PlaybackType()),
            .subtitle = winrt::to_string(mediaProperties.Subtitle()),
            .thumbnail = {}, // TODO: handle thumbnail data
            .title = winrt::to_string(mediaProperties.Title()),
            .trackNumber = mediaProperties.TrackNumber(),
        };
        m_service->systemMediaPropertiesChanged(mediaInfo);
    });

    m_playbackInfoToken = m_session.PlaybackInfoChanged([](GlobalSystemMediaTransportControlsSession session, PlaybackInfoChangedEventArgs args) {
        auto playbackInfo = session.GetPlaybackInfo();
        if (playbackInfo.PlaybackStatus() == GlobalSystemMediaTransportControlsSessionPlaybackStatus::Paused) {
            //TODO: handle pause event
        }
        else if (playbackInfo.PlaybackStatus() == GlobalSystemMediaTransportControlsSessionPlaybackStatus::Playing) {
            //TODO: handle play event
        }
    });
}
