/*
* File: ServiceController.cpp
* Author: trung.la
* Date: 01-08-2025
* Description: Implementation for Service Controller
*/

#include "ServiceController.h"

#include "IService.h"
#include "IServiceFactory.h"

#include "WindowMediaService/IWindowMediaService.h"

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

        IService* service = serviceFactory->factoryMethod(serviceName);
        if (!service)
        {
            continue;
        }

        m_services[serviceName] = ServiceUPtr(service);
        if (serviceName == "WindowMediaService")
        {
            IWindowMediaService* windowMediaService = dynamic_cast<IWindowMediaService*>(service);
            if (windowMediaService)
            {
                windowMediaService->start();
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
