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
#include "Utils/ServiceUtility.h"

ServiceController::ServiceController(QObject *parent)
    : QObject(parent)
{
}

ServiceController::~ServiceController()
{
}

void ServiceController::initialize()
{
    initializeServices();
}

void ServiceController::initializeServices()
{
    using namespace utils::service;
    for (const auto& service : getServiceNames())
    {
        IServiceFactory* serviceFactory = getServiceFactory();
        std::string serviceName = service.second;
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