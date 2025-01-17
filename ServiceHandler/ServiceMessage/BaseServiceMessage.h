/*
* File: BaseServiceMessage.h
* Author: trung.la
* Date: 01-15-2025
* Description: Implementation for Base Message
*/

#ifndef BASE_SERVICE_MESSAGE_H
#define BASE_SERVICE_MESSAGE_H

#include "ServiceMessage/ServiceMessageId.h"

class BaseServiceMessage
{
public:
    using ServiceMessageId = service_handler::service_message::ServiceMessageId;

    BaseServiceMessage(const ServiceMessageId& id) : m_id(id) {}
    BaseServiceMessage() = delete;
    virtual ~BaseServiceMessage() = default;

    ServiceMessageId getId() const { return m_id; }

private:
    ServiceMessageId m_id = ServiceMessageId::None;
};

#endif // BASE_MESSAGE_H