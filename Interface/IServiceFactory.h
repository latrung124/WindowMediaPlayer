/*
* File: IServiceFactory.h
* Author: trung.la
* Date: 01-07-2025
* Description: Interface for Service Factory
*/

#ifndef ISERVICE_FACTORY_H
#define ISERVICE_FACTORY_H

#include "Definitions.h"

class IService;

class SERVICE_FACTORY_API IServiceFactory
{
public:
    virtual ~IServiceFactory() = default;
    virtual IService* factoryMethod() const = 0;
};

#endif // ISERVICE_FACTORY_H