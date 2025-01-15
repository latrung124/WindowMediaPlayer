/*
* File: WPlaybackInfoMessage.cpp
* Author: trung.la
* Date: 01-15-2025
* Description: Implementation for Window Media Playback Info Message
*/

#include "WPlaybackInfoMessage.h"

WPlaybackInfoMessage::WPlaybackInfoMessage()
    : BaseServiceMessage(ServiceMessageId::WPlaybackInfoMessage)
{
}

void WPlaybackInfoMessage::setWPlaybackInfo(const WindowServiceUtils::WPlaybackInfo& wPlaybackInfo)
{
    m_wPlaybackInfo = wPlaybackInfo;
}

WindowServiceUtils::WPlaybackInfo WPlaybackInfoMessage::getWPlaybackInfo() const
{
    return m_wPlaybackInfo;
}