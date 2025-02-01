/*
* File: WindowMediaServiceHandler.cpp
* Author: trung.la
* Date: 01-15-2025
* Description: Implementation for Window Media Service Handler
*/

#include "WindowMediaServiceHandler.h"

#include "ServiceConsumer/WindowMediaService/WindowMediaServiceConsumer.h"
#include "ServiceMessage/WindowMediaService/WMediaInfoMessage.h"
#include "ServiceMessage/WindowMediaService/WPlaybackInfoMessage.h"
#include "ServiceMessage/WindowMediaService/WTimelinePropertiesMessage.h"
#include "MediaModule/MediaPlayerModel.h"

#include <QDebug>

WindowMediaServiceHandler::WindowMediaServiceHandler()
    : m_serviceConsumer(std::make_unique<WindowMediaServiceConsumer>(this))
    , m_mediaPlayerModel(std::make_unique<MediaPlayerModel>())
{
}

WindowMediaServiceHandler::~WindowMediaServiceHandler()
{
}

WindowMediaServiceHandler& WindowMediaServiceHandler::getInstance()
{
    static WindowMediaServiceHandler instance;
    return instance;
}

void WindowMediaServiceHandler::start()
{
    m_serviceConsumer->start();
}

void WindowMediaServiceHandler::stop()
{
    m_serviceConsumer->stop();
}

void WindowMediaServiceHandler::enqueueMessage(ServiceMessageUPtr message)
{
    m_serviceConsumer->addMessage(std::move(message));
}

void WindowMediaServiceHandler::processMessage(ServiceMessageUPtr message)
{
    using namespace service_handler::service_message;
    if (!message) {
        return;
    }

    ServiceMessageId messageId = message->getId();
    switch (messageId)
    {
    case ServiceMessageId::WMediaInfoMessage: {
        if (auto mediaInfoMessage = dynamic_cast<WMediaInfoMessage*>(message.get())) {
            m_mediaPlayerModel->updateMediaInfo(mediaInfoMessage->getMediaInfo());
        }
        break;
    }
    case ServiceMessageId::WPlaybackInfoMessage: {
        if (auto playbackInfoMessage = dynamic_cast<WPlaybackInfoMessage*>(message.get())) {
            m_mediaPlayerModel->updatePlaybackInfo(playbackInfoMessage->getWPlaybackInfo());
        }
        break;
    }
    case ServiceMessageId::WTimelinePropertiesMessage: {
        if (auto timelinePropertiesMessage = dynamic_cast<WTimelinePropertiesMessage*>(message.get())) {
            m_mediaPlayerModel->updateTimelineProperties(timelinePropertiesMessage->getWTimelineProperties());
        }
        break;
    }
    default:
        break;
    }
}

QObject* WindowMediaServiceHandler::getMediaPlayerModel() const
{
    return static_cast<QObject*>(m_mediaPlayerModel.get());
}
