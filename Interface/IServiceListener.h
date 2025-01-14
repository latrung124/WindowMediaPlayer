/*
* File: IServiceListener.h
* Author: trung.la
* Date: 01-14-2025
* Description: Interface for service listener
*/

#ifndef ISERVICE_LISTENER_H
#define ISERVICE_LISTENER_H

class IServiceListener
{
public:
    IServiceListener() = default;
    virtual ~IServiceListener() = default;

    IServiceListener(const IServiceListener&) = delete;
    IServiceListener& operator=(const IServiceListener&) = delete;
    IServiceListener(IServiceListener&&) = delete;
    IServiceListener& operator=(IServiceListener&&) = delete;
};

#endif // ISERVICE_LISTENER_H