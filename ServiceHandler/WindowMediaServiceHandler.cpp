/*
* File: WindowMediaServiceHandler.cpp
* Author: trung.la
* Date: 01-15-2025
* Description: Implementation for Window Media Service Handler
*/

#include "WindowMediaServiceHandler.h"

#include "ServiceConsumer/WindowMediaService/WindowMediaServiceConsumer.h"
#include "MediaModule/MediaPlayerModel.h"

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
    // Process message here
    m_mediaPlayerModel->update();
}
