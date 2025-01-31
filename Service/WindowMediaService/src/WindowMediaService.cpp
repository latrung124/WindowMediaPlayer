/*
* File: WindowMediaService.cpp
* Author: trung.la
* Date: 01-07-2025
* Description: Implementation for Window Media Service
*/

#include "WindowMediaService.h"
#include "WindowMediaService/IWindowMediaServiceListener.h"

WindowMediaService::WindowMediaService(WindowMediaService &&service) noexcept
{
    m_windowSystemMedia = std::move(service.m_windowSystemMedia);
    m_listeners = std::move(service.m_listeners);
}

WindowMediaService& WindowMediaService::operator=(WindowMediaService &&service) noexcept
{
    m_windowSystemMedia = std::move(service.m_windowSystemMedia);
    m_listeners = std::move(service.m_listeners);

    return *this;
}

void WindowMediaService::start()
{
    m_windowSystemMedia = std::make_unique<WindowSystemMedia>(this);
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

void WindowMediaService::systemMediaPropertiesChanged(const WindowServiceUtils::WMediaInfo &WMediaInfo)
{
    for (const auto& listener : m_listeners)
    {
        if (auto l = dynamic_cast<IWindowMediaServiceListener*>(listener))
        {
            l->onMediaInfoChanged(WMediaInfo);
        }
    }
}


void WindowMediaService::systemPlaybackInfoChanged(const WindowServiceUtils::WPlaybackInfo &playbackInfo)
{
    for (const auto& listener : m_listeners)
    {
        if (auto l = dynamic_cast<IWindowMediaServiceListener*>(listener))
        {
            l->onPlaybackInfoChanged(playbackInfo);
        }
    }
}

void WindowMediaService::systemTimelinePropertiesChanged(const WindowServiceUtils::WTimelineProperties &timelineProperties)
{
    for (const auto& listener : m_listeners)
    {
        if (auto l = dynamic_cast<IWindowMediaServiceListener*>(listener))
        {
            l->onTimelinePropertiesChanged(timelineProperties);
        }
    }
}