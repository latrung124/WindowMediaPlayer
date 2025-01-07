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

    using ServiceFactoryFunc = std::function<std::unique_ptr<ServiceFactory>()>;

    static ServiceFactory& instance();
    void registerCreator(const std::string& key, ServiceFactoryFunc func);
    std::unique_ptr<ServiceFactory> create(const std::string& key) const;

private:
    std::unordered_map<std::string, ServiceFactoryFunc> serviceFactories;
};

#endif // SERVICE_FACTORY_H