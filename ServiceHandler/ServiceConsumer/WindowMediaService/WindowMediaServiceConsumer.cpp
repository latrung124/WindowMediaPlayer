/*
* File: WindowMediaServiceConsumer.cpp
* Author: trung.la
* Date: 01-15-2025
* Description: Implementation for Window Media Service Consumer
*/

#include "WindowMediaServiceConsumer.h"
#include "ServiceMessage/BaseServiceMessage.h"
#include "WindowMediaServiceHandler.h"

#include "Utils/ThreadGuard.h"

WindowMediaServiceConsumer::WindowMediaServiceConsumer(WindowMediaServiceHandler *handler)
    : m_handler(handler)
    , m_isRunning(false)
{
}

WindowMediaServiceConsumer::~WindowMediaServiceConsumer()
{
    utils::ThreadGuard guard(m_looper);
}

void WindowMediaServiceConsumer::start()
{
    m_isRunning = true;
    m_looper = std::thread(&WindowMediaServiceConsumer::loop, this);
}

void WindowMediaServiceConsumer::stop()
{
    m_isRunning = false;
    m_conditionVariable.notify_all();
}

bool WindowMediaServiceConsumer::canConsume()
{
    return m_isRunning && !m_messageQueue.empty();
}

void WindowMediaServiceConsumer::addMessage(ServiceMessageUPtr message)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    m_messageQueue.push(std::move(message));
    m_conditionVariable.notify_all();
}

void WindowMediaServiceConsumer::loop()
{
    while (true) {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_conditionVariable.wait(lock, [this] {
            return canConsume();
        });

        if (!m_isRunning && m_messageQueue.empty()) {
            break;
        }

        if (m_handler) {
            auto message = std::move(m_messageQueue.front());
            m_messageQueue.pop();
            processMessage(std::move(message));
        }
    }
}

void WindowMediaServiceConsumer::processMessage(ServiceMessageUPtr message)
{
    if (m_handler) {
        m_handler->processMessage(std::move(message));
    }
}