/*
* File: WindowMediaService.cpp
* Author: trung.la
* Date: 01-07-2025
* Description: Implementation for Window Media Service
*/

#include "WindowMediaService.h"

void WindowMediaService::start()
{
    m_windowSystemMedia.systemInit();
}

void WindowMediaService::registerListener(const IServiceListener *listener)
{
    if (listener == nullptr)
    {
        return;
    }

    for (const auto& l : m_listeners)
    {
        if (l == listener)
        {
            return;
        }
    }

    m_listeners.push_back(const_cast<IServiceListener*>(listener));
}

void WindowMediaService::unregisterListener(const IServiceListener *listener)
{
    if (listener == nullptr)
    {
        return;
    }

    for (auto it = m_listeners.begin(); it != m_listeners.end(); ++it)
    {
        if (*it == listener)
        {
            m_listeners.erase(it);
            return;
        }
    }
}

void WindowMediaService::getMediaInfo()
{
}
