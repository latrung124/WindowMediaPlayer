/*
* CustomButtonBackground.qml
* Author: trung.la
* Date: 01-04-2025
* Brief: This file contains the CustomButtonBackground component which is used to create a custom button background.
*/

import QtQuick
import QtQuick.Controls
import Qt5Compat.GraphicalEffects

Item {
    id: root

    property bool isShowBackground: true
    property bool isShowIcon: false

    property alias iconSource: icon.source
    property alias iconColor: iconOverlay.color

    implicitWidth: internal.backgroundWidth
    implicitHeight: internal.backgroundHeight

    Rectangle {
        id: background

        visible: isShowBackground
        anchors.fill: parent
        color: internal.backgroundColor
        radius: internal.backgroundRadius
    }

    Image {
        id: icon

        visible: false
        anchors.centerIn: parent
        fillMode: Image.PreserveAspectFit
    }

    ColorOverlay {
        id: iconOverlay

        visible: isShowIcon
        anchors.fill: icon
        source: icon
    }

    QtObject {
        id: internal

        readonly property int backgroundWidth: 100
        readonly property int backgroundHeight: 50
        readonly property int backgroundRadius: 4
        readonly property color backgroundColor: "#000000"
    }
}