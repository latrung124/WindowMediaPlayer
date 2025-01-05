/*
* BottomMediaPlayer.qml
* Author: trung.la
* Date: 01-03-2025
* Description: This file contains the bottom media player of the application
*/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: root

    implicitHeight: 115
    implicitWidth: 1366

    Rectangle {
        id: backgroundRect

        anchors.fill: parent
        color: "#000000"
        radius: 8
        anchors.margins: 1
    }
}