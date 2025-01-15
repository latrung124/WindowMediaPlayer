/*
* File: WPlaybackControlsMessage.cpp
* Author: trung.la
* Date: 01-15-2025
* Description: Implementation for Window Media Playback Controls Message
*/

#include "WPlaybackControlsMessage.h"

WPlaybackControlsMessage::WPlaybackControlsMessage()
    : BaseServiceMessage(ServiceMessageId::WPlaybackControlsMessage)
{
}

void WPlaybackControlsMessage::setWPlaybackControls(const WindowServiceUtils::WPlaybackControls& wPlaybackControls)
{
    m_wPlaybackControls = wPlaybackControls;
}

WindowServiceUtils::WPlaybackControls WPlaybackControlsMessage::getWPlaybackControls() const
{
    return m_wPlaybackControls;
}
