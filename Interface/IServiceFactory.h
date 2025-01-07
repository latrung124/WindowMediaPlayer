/*
* File: IServiceFactory.h
* Author: trung.la
* Date: 01-07-2025
* Description: Interface for Service Factory
*/

#ifndef ISERVICE_FACTORY_H
#define ISERVICE_FACTORY_H

#include "Definitions.h"

#include <string>

#include "IService.h"

class SERVICE_FACTORY_API IServiceFactory
{
public:
    virtual ~IServiceFactory() = default;
    virtual IService* factoryMethod(std::string &serviceName) const = 0;
};

extern "C" SERVICE_FACTORY_API IServiceFactory* getServiceFactory();

#endif // ISERVICE_FACTORY_H
