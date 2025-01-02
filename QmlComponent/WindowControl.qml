/*
* File: WindowControl.qml
* Author: trung.la
* Date: 01-02-2025
* Brief: This file contains the WindowControl component which is used to control the window of the application.
*/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: root

    implicitWidth: 80
    implicitHeight: 20

    RowLayout {
        id: layout

        anchors.fill: parent
        spacing: 10

        Item {
            id: minimizeItem

            Layout.fillWidth: true
            Layout.fillHeight: true

            Image {
                id: minimizeImage

                anchors.fill: parent
                source: `Resources/minimize-button.png`
                fillMode: Image.PreserveAspectFit
            }
        }

        Item {
            id: maximizeItem

            Layout.fillWidth: true
            Layout.fillHeight: true

            Image {
                id: maximizeImage

                anchors.fill: parent
                source: `Resources/maximize-button.png`
                fillMode: Image.PreserveAspectFit
            }
        }

        Item {
            id: closeItem

            Layout.fillWidth: true
            Layout.fillHeight: true

            Image {
                id: closeImage

                anchors.fill: parent
                source: `Resources/close-button.png`
                fillMode: Image.PreserveAspectFit
            }
        }
    }
}
