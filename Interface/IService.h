/*
* File:  IService.h
* Author: trung.la
* Date: 01-07-2025
* Description: Interface for Window Media Service
*/

#ifndef ISERVICE_H
#define ISERVICE_H

#include "IServiceListener.h"

class IService
{
public:
    IService() = default;
    virtual ~IService() = default;

    virtual void registerListener(const IServiceListener *listener) = 0;
    virtual void unregisterListener(const IServiceListener *listener) = 0;

    IService(const IService&) = delete;
    IService& operator=(const IService&) = delete;
    IService(IService&&) = delete;
    IService& operator=(IService&&) = delete;
};

#endif // ISERVICE_H
