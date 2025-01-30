/*
* File: WindowMediaServiceListener.cpp
* Author: trung.la
* Date: 01-14-2025
* Description: Implementation for Window Media Service Listener
*/

#include "WindowMediaServiceListener.h"

#include "ServiceMessage/WindowMediaService/WMediaInfoMessage.h"
#include "ServiceMessage/WindowMediaService/WPlaybackControlsMessage.h"
#include "ServiceMessage/WindowMediaService/WPlaybackInfoMessage.h"

#include "WindowMediaServiceHandler.h"

void WindowMediaServiceListener::onMediaInfoChanged(const WMediaInfo &mediaInfo)
{
    auto message = std::make_unique<WMediaInfoMessage>();
    message->setMediaInfo(mediaInfo);
    WindowMediaServiceHandler::getInstance().enqueueMessage(std::move(message));
}

void WindowMediaServiceListener::onPlaybackControlsChanged(const WPlaybackControls &playbackControls)
{
    auto message = std::make_unique<WPlaybackControlsMessage>();
    message->setWPlaybackControls(playbackControls);
    WindowMediaServiceHandler::getInstance().enqueueMessage(std::move(message));
}

void WindowMediaServiceListener::onPlaybackInfoChanged(const WPlaybackInfo &playbackInfo)
{
    auto message = std::make_unique<WPlaybackInfoMessage>();
    message->setWPlaybackInfo(playbackInfo);
    WindowMediaServiceHandler::getInstance().enqueueMessage(std::move(message));
}