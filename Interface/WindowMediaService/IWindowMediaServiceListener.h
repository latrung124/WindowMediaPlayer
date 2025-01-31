/*
* File: IWindowMediaServiceListener.h
* Author: trung.la
* Date: 01-14-2025
* Description: Interface for Window Media Service Listener
*/

#ifndef IWINDOW_MEDIA_SERVICE_LISTENER_H
#define IWINDOW_MEDIA_SERVICE_LISTENER_H

#include "IServiceListener.h"
#include "WindowServiceUtils.h"

class IWindowMediaServiceListener : public IServiceListener
{
public:
    using WMediaInfo = WindowServiceUtils::WMediaInfo;
    using WPlaybackControls = WindowServiceUtils::WPlaybackControls;
    using WPlaybackInfo = WindowServiceUtils::WPlaybackInfo;
    using WTimelineProperties = WindowServiceUtils::WTimelineProperties;

    IWindowMediaServiceListener() = default;
    virtual ~IWindowMediaServiceListener() = default;

    virtual void onMediaInfoChanged(const WMediaInfo &mediaInfo) = 0;
    virtual void onPlaybackControlsChanged(const WPlaybackControls &playbackControls) = 0;
    virtual void onPlaybackInfoChanged(const WPlaybackInfo &playbackInfo) = 0;
    virtual void onTimelinePropertiesChanged(const WTimelineProperties &timelineProperties) = 0;
};

#endif // IWINDOW_MEDIA_SERVICE_LISTENER_H