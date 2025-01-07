/*
* File: ServiceFactory.cpp
* Author: trung.la
* Date: 01-07-2025
* Description: Implementation for Service Factory
*/

#include "ServiceFactory.h"
#include "WindowMediaService/include/WindowMediaService.h"

IService* ServiceFactory::factoryMethod(std::string &serviceName) const
{
    if (serviceName == "WindowMediaService")
    {
        return new WindowMediaService();
    }

    return nullptr;
}
