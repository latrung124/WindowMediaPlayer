/*
* File:  IWindowMediaService.h
* Author: trung.la
* Date: 01-07-2025
* Description: Interface for Window Media Service
*/

#ifndef IWINDOWMEDIASERVICE_H
#define IWINDOWMEDIASERVICE_H

#include "Definitions.h"
#include "IService.h"

class WMEDIA_SERVICE_API IWindowMediaService : public IService
{
public:
    ~IWindowMediaService() = default;

    virtual void start() = 0;
    virtual void getMediaInfo() = 0;
};

#endif // IWINDOWMEDIASERVICE_H