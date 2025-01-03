/*
* File: MainContent.qml
* Author: trung.la
* Date: 01-03-2025
* Description: This file contains the main content of the application
*/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: root

    implicitHeight: 580
    implicitWidth: 1366

    RowLayout {
        id: layout

        anchors.fill: parent
        spacing: 10

        Rectangle {
            id: leftRect

            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "#999999"
            radius: 8
        }

        Rectangle {
            id: centerRect

            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "#999999"
            radius: 8
        }

        Rectangle {
            id: rightRect

            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "#999999"
            radius: 8
        }
    }
}
