/*
* File: BaseServiceConsumer.h
* Author: trung.la
* Date: 01-15-2025
* Description: Implementation for Base Service Consumer
*/

#ifndef BASE_SERVICE_CONSUMER_H
#define BASE_SERVICE_CONSUMER_H

#include "ServiceMessage/BaseServiceMessage.h"

#include <memory>

class BaseServiceConsumer
{
public:
    BaseServiceConsumer() = default;
    virtual ~BaseServiceConsumer() = default;

    BaseServiceConsumer(const BaseServiceConsumer&) = delete;
    BaseServiceConsumer& operator=(const BaseServiceConsumer&) = delete;
    BaseServiceConsumer(BaseServiceConsumer&&) = delete;
    BaseServiceConsumer& operator=(BaseServiceConsumer&&) = delete;

    virtual void addMessage(std::unique_ptr<BaseServiceMessage> msg) = 0;
};

#endif // BASE_SERVICE_CONSUMER_H
