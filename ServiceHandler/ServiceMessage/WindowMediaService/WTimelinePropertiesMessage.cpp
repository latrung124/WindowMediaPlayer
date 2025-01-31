/*
* WTimelinePropertiesMessage.cpp
* Author: trung.la
* Date: 01-31-2025
* Description: Implementation for Window Media Timeline Properties Message
*/

#include "WTimelinePropertiesMessage.h"

WTimelinePropertiesMessage::WTimelinePropertiesMessage()
    : BaseServiceMessage(ServiceMessageId::WTimelinePropertiesMessage)
{
}

void WTimelinePropertiesMessage::setWTimelineProperties(const WindowServiceUtils::WTimelineProperties& wTimelineProperties)
{
    m_wTimelineProperties = wTimelineProperties;
}

WindowServiceUtils::WTimelineProperties WTimelinePropertiesMessage::getWTimelineProperties() const
{
    return m_wTimelineProperties;
}

