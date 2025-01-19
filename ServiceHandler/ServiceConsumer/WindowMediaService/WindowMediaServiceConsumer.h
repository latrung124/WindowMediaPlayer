/*
* File: WindowMediaServiceConsumer.h
* Author: trung.la
* Date: 01-15-2025
* Description: Implementation for Window Media Service Consumer
*/

#ifndef WINDOW_MEDIA_SERVICE_CONSUMER_H
#define WINDOW_MEDIA_SERVICE_CONSUMER_H

#include "ServiceConsumer/BaseServiceConsumer.h"
#include "Utils/ThreadGuard.h"

#include <mutex>
#include <condition_variable>
#include <queue>
#include <memory>

class WindowMediaServiceHandler;

class WindowMediaServiceConsumer : public BaseServiceConsumer
{
public:
    using ServiceMessageUPtr = std::unique_ptr<BaseServiceMessage>;

    WindowMediaServiceConsumer(WindowMediaServiceHandler* handler);
    ~WindowMediaServiceConsumer();

    WindowMediaServiceConsumer(const WindowMediaServiceConsumer&) = delete;
    WindowMediaServiceConsumer& operator=(const WindowMediaServiceConsumer&) = delete;

    WindowMediaServiceConsumer(WindowMediaServiceConsumer&&) = delete;
    WindowMediaServiceConsumer& operator=(WindowMediaServiceConsumer&&) = delete;

    void start() override;
    void stop() override;

    void addMessage(ServiceMessageUPtr message) override;

private:
    void loop();
    bool canConsume();

    void processMessage(ServiceMessageUPtr message);

    mutable std::mutex m_mutex;
    std::thread m_looper;
    std::condition_variable m_conditionVariable;
    std::queue<ServiceMessageUPtr> m_messageQueue;
    bool m_isRunning;
    WindowMediaServiceHandler* m_handler = nullptr;
};

#endif // WINDOW_MEDIA_SERVICE_CONSUMER_H