/*
* File: ServiceFactory.h
* Author: trung.la
* Date: 01-07-2025
* Description: Implementation for Service Factory
*/

#ifndef SERVICE_FACTORY_H
#define SERVICE_FACTORY_H

#include "IServiceFactory.h"

#include <functional>
#include <memory>
#include <unordered_map>
#include <string>

class SERVICE_FACTORY_API ServiceFactory : public IServiceFactory
{
public:
    virtual ~ServiceFactory() = default;
    IService* factoryMethod(std::string &serviceName) const override;
};

extern "C" SERVICE_FACTORY_API IServiceFactory* getServiceFactory() {
    static ServiceFactory factory;
    return &factory;
}

#endif // SERVICE_FACTORY_H