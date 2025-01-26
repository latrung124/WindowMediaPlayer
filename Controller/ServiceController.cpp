/*
* File: ServiceController.cpp
* Author: trung.la
* Date: 01-08-2025
* Description: Implementation for Service Controller
*/

#include "ServiceController.h"

#include <QQmlApplicationEngine>

#include "IService.h"
#include "IServiceFactory.h"

#include "WindowMediaService/IWindowMediaService.h"
#include "WindowMediaServiceHandler.h"

#include "ServiceListener/WindowMediaService/WindowMediaServiceListener.h"

#include "Utils/ServiceUtility.h"

ServiceController::ServiceController(QObject *parent)
    : QObject(parent)
{
}

ServiceController::~ServiceController()
{
}

ServiceController& ServiceController::getInstance()
{
    static ServiceController instance;
    return instance;
}

void ServiceController::initialize()
{
    initializeServices();
    registerListeners();
}

void ServiceController::initializeServices()
{
    using namespace utils::service;
    for (const auto& s : getServiceNames())
    {
        IServiceFactory* serviceFactory = getServiceFactory();
        std::string serviceName = s.second;
        if (!serviceFactory)
        {
            return;
        }

        const auto service = serviceFactory->factoryMethod(serviceName);
        if (!service) {
            return;
        }

        m_services[serviceName] = ServiceUPtr(std::move(service)); // TODO: Apply rule of five for services.
        if (serviceName == "WindowMediaService")
        {
            if (auto windowMediaService = dynamic_cast<IWindowMediaService*>(m_services[serviceName].get())) {
                windowMediaService->start();
                // Start WindowMediaServiceHandler
                WindowMediaServiceHandler::getInstance().start();
                // TODO: stop handler when service died.
            }
        }
    }
}

void ServiceController::registerListeners()
{
    using namespace utils::service;
    for (const auto& s : getServiceNames())
    {
        std::string serviceName = s.second;
        if (m_services[serviceName] == nullptr)
        {
            continue;
        }
        m_services[serviceName]->registerListener(new WindowMediaServiceListener());
    }
}

void ServiceController::onModuleLoadedSucceed(const EnginePtr &engine)
{
    m_engine = engine;
    initializeModels();
}

void ServiceController::initializeModels()
{
    // TODO: set some service models in qml
    const auto engine = m_engine.lock();
    if (!engine)
        return;
 
    const auto rootObj = engine->rootObjects().first();
    if (!rootObj)
        return;

    const auto bottomMediaPlayerObj = rootObj->findChild<QObject*>("bottomMediaPlayer");
    if (!bottomMediaPlayerObj)
        return;

    bottomMediaPlayerObj->setProperty("mediaPlayerModel", QVariant::fromValue(WindowMediaServiceHandler::getInstance().getMediaPlayerModel()));
}