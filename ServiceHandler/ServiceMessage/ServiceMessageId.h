/*
* File: ServiceMessageId.h
* Author: trung.la
* Date: 01-15-2025
* Description: Implementation for Service Message Id
*/

#ifndef SERVICE_MESSAGE_ID_H
#define SERVICE_MESSAGE_ID_H

#include <cstdint>

namespace service_handler
{

namespace service_message
{

enum class ServiceMessageId : uint16_t
{
    None = 0,
    WMediaInfoMessage = 1,
    WPlaybackControlsMessage = 2,
    WPlaybackInfoMessage = 3,
};

} // namespace service_handler::service_message

} // namespace service_handler

#endif // SERVICE_MESSAGE_ID_H