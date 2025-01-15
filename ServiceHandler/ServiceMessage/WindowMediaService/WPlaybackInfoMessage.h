/*
* File: WPlaybackInfoMessage.h
* Author: trung.la
* Date: 01-15-2025
* Description: Implementation for Window Media Playback Info Message
*/

#ifndef W_PLAYBACK_INFO_MESSAGE_H
#define W_PLAYBACK_INFO_MESSAGE_H

#include "Interface/WindowMediaService/WindowServiceUtils.h"
#include "ServiceMessage/BaseServiceMessage.h"

class WPlaybackInfoMessage : public BaseServiceMessage
{
public:
    WPlaybackInfoMessage();
    ~WPlaybackInfoMessage() = default;

    void setWPlaybackInfo(const WindowServiceUtils::WPlaybackInfo& wPlaybackInfo);
    WindowServiceUtils::WPlaybackInfo getWPlaybackInfo() const;

private:
    WindowServiceUtils::WPlaybackInfo m_wPlaybackInfo;
};

#endif // W_PLAYBACK_INFO_MESSAGE_H