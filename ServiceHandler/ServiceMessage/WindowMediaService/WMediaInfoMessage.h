/*
* File: WMediaInfoMessage.h
* Author: trung.la
* Date: 01-15-2025
* Description: Implementation for Window Media Info Message
*/

#ifndef W_MEDIA_INFO_MESSAGE_H
#define W_MEDIA_INFO_MESSAGE_H

#include "Interface/WindowMediaService/WindowServiceUtils.h"
#include "ServiceMessage/BaseServiceMessage.h"

class WMediaInfoMessage : public BaseServiceMessage
{
public:
    WMediaInfoMessage();
    ~WMediaInfoMessage() = default;

    void setMediaInfo(const WindowServiceUtils::WMediaInfo& mediaInfo);
    WindowServiceUtils::WMediaInfo getMediaInfo() const;

private:
    WindowServiceUtils::WMediaInfo m_mediaInfo;
};

#endif // W_MEDIA_INFO_MESSAGE_H