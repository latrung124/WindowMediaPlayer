/*
* File: WindowSystemMedia.h
* Author: trung.la
* Date: 01-09-2025
* Description: Implementation of window system media
*/

#ifndef WINDOW_SYSTEM_MEDIA_H
#define WINDOW_SYSTEM_MEDIA_H

#include <winrt/windows.media.control.h>

class WindowSystemMedia
{
public:
    using GlobalSystemMediaTransportControlsSessionManager = winrt::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionManager;
    using GlobalSystemMediaTransportControlsSession = winrt::Windows::Media::Control::GlobalSystemMediaTransportControlsSession;
    WindowSystemMedia() = default;
    ~WindowSystemMedia() = default;

    bool systemInit();

private:
    GlobalSystemMediaTransportControlsSessionManager m_sessionManager{ nullptr };
    GlobalSystemMediaTransportControlsSession m_session{ nullptr };
};

#endif // WINDOW_SYSTEM_MEDIA_H
