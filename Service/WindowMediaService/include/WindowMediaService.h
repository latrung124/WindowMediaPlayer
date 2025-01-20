/*
* File: WindowMediaService.h
* Author: trung.la
* Date: 01-07-2025
* Description: Implementation for Window Media Service
*/

#ifndef WINDOWMEDIASERVICE_H
#define WINDOWMEDIASERVICE_H

#include "WindowMediaService/WindowServiceUtils.h"
#include "WindowMediaService/IWindowMediaService.h"
#include "WindowSystemMedia.h"

#include <memory>
#include <vector>

class WMEDIA_SERVICE_API WindowMediaService : public IWindowMediaService
{
public:
    WindowMediaService() = default;
    ~WindowMediaService() = default;

    WindowMediaService(const WindowMediaService &service) = delete;
    WindowMediaService& operator=(const WindowMediaService &service) = delete;
    WindowMediaService(WindowMediaService &&service) noexcept;
    WindowMediaService& operator=(WindowMediaService &&service) noexcept;

    virtual void registerListener(const IServiceListener *listener) override;
    virtual void unregisterListener(const IServiceListener *listener) override;

    virtual void start() override;
    virtual void getMediaInfo() override;

    void systemMediaPropertiesChanged(const WindowServiceUtils::WMediaInfo &WMediaInfo);

private:
    std::unique_ptr<WindowSystemMedia> m_windowSystemMedia = nullptr;
    std::vector<IServiceListener*> m_listeners;
};

#endif // WINDOWMEDIASERVICE_H
