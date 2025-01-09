/*
* File: WindowMediaService.h
* Author: trung.la
* Date: 01-07-2025
* Description: Implementation for Window Media Service
*/

#ifndef WINDOWMEDIASERVICE_H
#define WINDOWMEDIASERVICE_H

#include "WindowMediaService/IWindowMediaService.h"
#include "WindowSystemMedia.h"

class WMEDIA_SERVICE_API WindowMediaService : public IWindowMediaService
{
public:
    virtual ~WindowMediaService() = default;

    virtual void start() override;
    virtual void getMediaInfo() override;

private:
    WindowSystemMedia m_windowSystemMedia;
};

#endif // WINDOWMEDIASERVICE_H
