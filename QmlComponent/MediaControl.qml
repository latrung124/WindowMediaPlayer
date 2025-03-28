/*
* MediaControl.qml
* Author: trung.la
* Date: 01-03-2025
* Description: This file contains the media control of the application
*/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: root

    implicitHeight: 50
    implicitWidth: 264 // 32 per button * 4 normal buttons + 22 spacing + 48 size of play/pause button

    property bool isShuffleEnabled: false
    property bool isRepeatEnabled: false
    property bool isPlaying: false
    property bool isPlayingEnabled: false
    property bool isPauseEnabled: false
    property bool isPreviousEnabled: false
    property bool isNextEnabled: false

    RowLayout {
        id: layout

        anchors.fill: parent
        spacing: 22

        CustomButton {
            id: shuffleItem

            Layout.fillWidth: true
            Layout.fillHeight: true
            iconSource: `Resources/shuffle-button.png`
            iconColor: isShuffleEnabled ? internal.enableColor : internal.disableColor
            isShowIcon: true
            isShowBackground: true
        }

        CustomButton {
            id: previousItem

            Layout.fillWidth: true
            Layout.fillHeight: true
            iconSource: `Resources/previous-button.png`
            iconColor: isPreviousEnabled ? internal.enableColor : internal.disableColor
            isShowIcon: true
            isShowBackground: true
        }

        CustomButton {
            id: playPauseItem

            Layout.fillWidth: true
            Layout.fillHeight: true
            iconSource: isPlaying ? `Resources/pause-button.png` : `Resources/play-button.png`
            iconColor: (isPlayingEnabled || isPauseEnabled) ? internal.enableColor : internal.disableColor
            isShowIcon: true
            isShowBackground: true
        }

        CustomButton {
            id: nextItem

            Layout.fillWidth: true
            Layout.fillHeight: true
            iconSource: `Resources/next-button.png`
            iconColor: isNextEnabled ? internal.enableColor : internal.disableColor
            isShowIcon: true
            isShowBackground: true
        }

        CustomButton {
            id: repeatItem

            Layout.fillWidth: true
            Layout.fillHeight: true
            iconSource: `Resources/repeat-button.png`
            iconColor: isRepeatEnabled ? internal.enableColor : internal.disableColor
            isShowIcon: true
            isShowBackground: true
        }
    }

    QtObject {
        id: internal

        readonly property color enableColor: "#FFFFFF"
        readonly property color disableColor: "#666666"
    }
}