/*
* File: WPlaybackControlsMessage.h
* Author: trung.la
* Date: 01-15-2025
* Description: Implementation for Window Media Playback Controls Message
*/

#ifndef W_MEDIA_PLAYBACK_CONTROLS_MESSAGE_H
#define W_MEDIA_PLAYBACK_CONTROLS_MESSAGE_H

#include "Interface/WindowMediaService/WindowServiceUtils.h"
#include "ServiceMessage/BaseServiceMessage.h"

class WPlaybackControlsMessage : public BaseServiceMessage
{
public:
    WPlaybackControlsMessage();
    ~WPlaybackControlsMessage() = default;

    void setWPlaybackControls(const WindowServiceUtils::WPlaybackControls& wPlaybackControls);
    WindowServiceUtils::WPlaybackControls getWPlaybackControls() const;

private:
    WindowServiceUtils::WPlaybackControls m_wPlaybackControls;
};

#endif // W_MEDIA_PLAYBACK_CONTROLS_MESSAGE_H