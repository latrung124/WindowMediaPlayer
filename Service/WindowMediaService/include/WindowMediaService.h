/*
* File: WindowMediaService.h
* Author: trung.la
* Date: 01-07-2025
* Description: Implementation for Window Media Service
*/

#ifndef WINDOWMEDIASERVICE_H
#define WINDOWMEDIASERVICE_H

#include "WindowMediaService/IWindowMediaService.h"

class WindowMediaService : public IWindowMediaService
{
public:
    virtual ~WindowMediaService() = default;
    virtual void getMediaInfo() override;
};

#endif // WINDOWMEDIASERVICE_H
