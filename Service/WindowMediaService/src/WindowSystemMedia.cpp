/*
* File: WindowSystemMedia.cpp
* Author: trung.la
* Date: 01-09-2025
* Description: Implementation of window system media
*/

#include "WindowSystemMedia.h"

#include <winrt/Windows.Foundation.h>

#include <iostream>

namespace {

using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::Media::Control;

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

    m_mediaPropertiesToken = m_session.MediaPropertiesChanged([](GlobalSystemMediaTransportControlsSession session, MediaPropertiesChangedEventArgs args) {
        //TODO: handle media properties changed
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
