/*
* File:  WMediaInfoMessage.cpp
* Author: trung.la
* Date: 01-15-2025
* Description: Implementation for Window Media Info Message
*/

#include "WMediaInfoMessage.h"

WMediaInfoMessage::WMediaInfoMessage()
    : BaseServiceMessage(ServiceMessageId::WMediaInfoMessage)
{
}

void WMediaInfoMessage::setMediaInfo(const WindowServiceUtils::WMediaInfo& mediaInfo)
{
    m_mediaInfo = mediaInfo;
}

WindowServiceUtils::WMediaInfo WMediaInfoMessage::getMediaInfo() const
{
    return m_mediaInfo;
}