/*
* File: WindowMediaServiceHandler.h
* Author: trung.la
* Date: 01-15-2025
* Description: Implementation for Window Media Service Handler
*/

#ifndef WINDOW_MEDIA_SERVICE_HANDLER_H
#define WINDOW_MEDIA_SERVICE_HANDLER_H

#include "BaseHandler.h"

#include <memory>

class BaseServiceConsumer;

class WindowMediaServiceHandler : public BaseHandler
{
public:
    using ServiceConsumerUPtr = std::unique_ptr<BaseServiceConsumer>;

    ~WindowMediaServiceHandler();
    static WindowMediaServiceHandler& getInstance();

private:
    WindowMediaServiceHandler();

    ServiceConsumerUPtr m_serviceConsumer;
};

#endif // WINDOW_MEDIA_SERVICE_HANDLER_H