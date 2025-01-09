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
        m_session = m_sessionManager.GetCurrentSession();
        if (m_session) {
            std::cout << "There is no media playing in your system" << std::endl;
        }
    } catch(winrt::hresult_error const& ex) {
        winrt::hstring message = ex.message();
        std::wcout << "An error occurs: " << message.c_str() << std::endl;
    }

    return true;
}
