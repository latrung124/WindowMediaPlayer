/*
* File: BaseServiceConsumer.h
* Author: trung.la
* Date: 01-15-2025
* Description: Implementation for Base Service Consumer
*/

#ifndef BASE_SERVICE_CONSUMER_H
#define BASE_SERVICE_CONSUMER_H

class BaseServiceConsumer
{
public:
    BaseServiceConsumer() = default;
    virtual ~BaseServiceConsumer() = default;

    BaseServiceConsumer(const BaseServiceConsumer&) = delete;
    BaseServiceConsumer& operator=(const BaseServiceConsumer&) = delete;
    BaseServiceConsumer(BaseServiceConsumer&&) = delete;
    BaseServiceConsumer& operator=(BaseServiceConsumer&&) = delete;
};

#endif // BASE_SERVICE_CONSUMER_H