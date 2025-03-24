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
{
}

WindowMediaServiceConsumer::~WindowMediaServiceConsumer()
{
    utils::ThreadGuard guard(m_looper);
}

void WindowMediaServiceConsumer::start()
{
    m_stopFlag.store(false);
    m_looper = std::thread(&WindowMediaServiceConsumer::loop, this);
}

void WindowMediaServiceConsumer::stop()
{
    m_stopFlag.store(true);
    m_conditionVariable.notify_one();
    utils::ThreadGuard guard(m_looper);
}

bool WindowMediaServiceConsumer::canConsume()
{
    return m_stopFlag.load() || !m_messageQueue.empty();
}

void WindowMediaServiceConsumer::addMessage(ServiceMessageUPtr message)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    m_messageQueue.push(std::move(message));
    m_conditionVariable.notify_one();
}

void WindowMediaServiceConsumer::loop()
{
    while (true) {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_conditionVariable.wait(lock, [this] {
            return canConsume();
        });

        if (m_stopFlag.load() && m_messageQueue.empty()) {
            break;
        }

        if (!m_messageQueue.empty() && m_handler) {
            auto message = std::move(m_messageQueue.front());
            m_messageQueue.pop();
            processMessage(std::move(message));
        }
    }
}

void WindowMediaServiceConsumer::processMessage(ServiceMessageUPtr message)
{
    m_handler->processMessage(std::move(message));
}
