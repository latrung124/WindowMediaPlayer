/*
* File: WindowSystemMedia.h
* Author: trung.la
* Date: 01-09-2025
* Description: Implementation of window system media
*/

#ifndef WINDOW_SYSTEM_MEDIA_H
#define WINDOW_SYSTEM_MEDIA_H

#include <winrt/windows.media.control.h>

class WindowMediaService;

class WindowSystemMedia
{
public:
    using GlobalSystemMediaTransportControlsSessionManager = winrt::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionManager;
    using GlobalSystemMediaTransportControlsSession = winrt::Windows::Media::Control::GlobalSystemMediaTransportControlsSession;

    WindowSystemMedia() = default;
    WindowSystemMedia(WindowMediaService* service);
    ~WindowSystemMedia() = default;

    WindowSystemMedia(const WindowSystemMedia &service) = delete;
    WindowSystemMedia& operator=(const WindowSystemMedia &&service) noexcept = delete;

    WindowSystemMedia(WindowSystemMedia &&service) noexcept;
    WindowSystemMedia& operator=(WindowSystemMedia &&service) noexcept;

    bool systemInit();

private:
    void registerCurrentSessionChangedEvents();
    void registerSessionPropertiesChangedEvents();

    void removeOldTempThumbnail();

    GlobalSystemMediaTransportControlsSessionManager m_sessionManager{ nullptr };
    GlobalSystemMediaTransportControlsSession m_session{ nullptr };

    winrt::event_token m_sessionChangedToken;
    winrt::event_token m_mediaPropertiesToken;
    winrt::event_token m_playbackInfoToken;

    WindowMediaService* m_service;
    std::string m_thumbnailPath = "";
};

#endif // WINDOW_SYSTEM_MEDIA_H
