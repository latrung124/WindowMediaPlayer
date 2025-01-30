/*
* File: WindowMediaServiceListener.h
* Author: trung.la
* Date: 01-14-2025
* Description: Implementation for Window Media Service Listener
*/

#ifndef WINDOW_MEDIA_SERVICE_LISTENER_H
#define WINDOW_MEDIA_SERVICE_LISTENER_H

#include "Interface/WindowMediaService/IWindowMediaServiceListener.h"

class WindowMediaServiceListener : public IWindowMediaServiceListener
{
public:
    WindowMediaServiceListener() = default;
    ~WindowMediaServiceListener() = default;

    void onMediaInfoChanged(const WMediaInfo &mediaInfo) override;
    void onPlaybackControlsChanged(const WPlaybackControls &playbackControls) override;
    void onPlaybackInfoChanged(const WPlaybackInfo &playbackInfo) override;
};

#endif // WINDOW_MEDIA_SERVICE_LISTENER_H