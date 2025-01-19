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

class BaseServiceMessage;
class BaseServiceConsumer;
class MediaPlayerModel;

class WindowMediaServiceHandler : public BaseHandler
{
public:
    using ServiceMessageUPtr = std::unique_ptr<BaseServiceMessage>;
    using ServiceConsumerUPtr = std::unique_ptr<BaseServiceConsumer>;
    using MediaPlayerModelUPtr = std::unique_ptr<MediaPlayerModel>;

    ~WindowMediaServiceHandler();
    static WindowMediaServiceHandler& getInstance();

    void start();
    void stop();

    void enqueueMessage(ServiceMessageUPtr message);
    void processMessage(ServiceMessageUPtr message);

private:
    WindowMediaServiceHandler();

    MediaPlayerModelUPtr m_mediaPlayerModel;
    ServiceConsumerUPtr m_serviceConsumer;
};

#endif // WINDOW_MEDIA_SERVICE_HANDLER_H