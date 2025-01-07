/*
* File: WMediaServiceFactory.h
* Author: trung.la
* Date: 01-07-2025
* Descriptiton: This class is declares the factory method that is supposed to return an Media Service Object.
*/

#ifndef WMEDIA_SERVICE_FACTORY_H
#define WMEDIA_SERVICE_FACTORY_H

#include "ServiceFactory.h"

class SERVICE_FACTORY_API WMediaServiceFactory : public ServiceFactory
{
public:
    virtual ~WMediaServiceFactory() = default;
    virtual IService* factoryMethod() const override;
};
#endif // WMEDIA_SERVICE_FACTORY_H