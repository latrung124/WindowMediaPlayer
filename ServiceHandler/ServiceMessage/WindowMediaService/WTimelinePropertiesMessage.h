/*
* WTimelinePropertiesMessage.h
* Author: trung.la
* Date: 01-31-2025
* Description: Implementation for Window Media Timeline Properties Message
*/

#ifndef W_TIMELINE_PROPERTIES_MESSAGE_H
#define W_TIMELINE_PROPERTIES_MESSAGE_H

#include "ServiceMessage/BaseServiceMessage.h"
#include "Interface/WindowMediaService/WindowServiceUtils.h"

class WTimelinePropertiesMessage : public BaseServiceMessage
{
public:
    WTimelinePropertiesMessage();
    ~WTimelinePropertiesMessage() = default;

    void setWTimelineProperties(const WindowServiceUtils::WTimelineProperties& wTimelineProperties);
    WindowServiceUtils::WTimelineProperties getWTimelineProperties() const;

private:
    WindowServiceUtils::WTimelineProperties m_wTimelineProperties;
};
#endif // W_TIMELINE_PROPERTIES_MESSAGE_H
