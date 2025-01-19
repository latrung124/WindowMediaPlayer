/*
* File: WindowServiceUtils.h
* Author: trung.la
* Date: 01-13-2025
* Description: Utility functions for Window Service
*/

#ifndef WINDOW_SERVICE_UTILS_H
#define WINDOW_SERVICE_UTILS_H

#include <string>
#include <stdint.h>
#include <vector>

namespace WindowServiceUtils
{
    enum class WMediaPlaybackType : uint16_t
    {
        Unknown = 0,
        Music = 1,
        Video = 2,
        Image = 3
    };

    enum class WMediaPlaybackAutoRepeatMode : uint16_t
    {
        None = 0,
        Track = 1,
        List = 2
    };

    enum WMediaPlaybackStatus : uint16_t
    {
        Closed = 0,
        Opened = 1,
        Changing = 2,
        Stopped = 3,
        Playing = 4,
        Paused = 5
    };

    struct WMediaInfo
    {
        std::string albumTitle = "";
        std::string albumArtist = "";
        int32_t totalTracks = 0;
        std::string artist = "";
        std::vector<std::string> genres = {};
        WMediaPlaybackType playbackType = WMediaPlaybackType::Unknown;
        std::string subtitle = "";
        std::vector<uint8_t> thumbnail = {};
        std::string title = "";
        int32_t trackNumber = 0;
    };

    struct WPlaybackControls
    {
        bool isChannelDownEnabled = false;
        bool isChannelUpEnabled = false;
        bool isFastForwardEnabled = false;
        bool isNextEnabled = false;
        bool isPauseEnabled = false;
        bool isPlaybackPositionEnabled = false;
        bool isPlaybackRateEnabled = false;
        bool isPlayEnabled = false;
        bool isPlayPauseToggleEnabled = false;
        bool isPreviousEnabled = false;
        bool isRecordEnabled = false;
        bool isRepeatEnabled = false;
        bool isRewindEnabled = false;
        bool isShuffleEnabled = false;
        bool isStopEnabled = false;
    };

    struct WPlaybackInfo
    {
        WMediaPlaybackAutoRepeatMode autoRepeatMode = WMediaPlaybackAutoRepeatMode::None;
        WPlaybackControls playbackControls = {};
        bool isShuffled = false;
        double playbackRate = 0.0;
        WMediaPlaybackStatus playbackStatus = WMediaPlaybackStatus::Closed;
        WMediaPlaybackType playbackType = WMediaPlaybackType::Unknown;
    };
}

#endif // WINDOW_SERVICE_UTILS_H
