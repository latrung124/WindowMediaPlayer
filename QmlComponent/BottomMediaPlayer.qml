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

    RowLayout {
        id: layout

        anchors {
            left: parent.left
            right: parent.right
            top: parent.top
            bottom: parent.bottom
            margins: internal.margin
        }
        spacing: 0

        Item {
            id: albumArtItem

            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.alignment: Qt.AlignLeft
            Rectangle {
                id: albumArtRect

                width: internal.imageSize
                height: internal.imageSize
                anchors {
                    verticalCenter: parent.verticalCenter
                    left: parent.left
                }
            }
        }

        MediaControl {
            id: mediaControl

            Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
        }

        Item {
            id: volumeControlItem

            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.alignment: Qt.AlignRight

            Rectangle {
                id: volumeControlRect

                width: 200
                height: 40
                anchors {
                    verticalCenter: parent.verticalCenter
                    right: parent.right
                }
            }
        }
    }

    QtObject {
        id: internal

        readonly property int margin: 10
        readonly property int imageSize: 60
    }
}
