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

    RowLayout {
        id: layout

        anchors.fill: parent
        spacing: 22

        Item {
            id: shuffleItem

            Layout.fillWidth: true
            Layout.fillHeight: true

            Rectangle {
                id: shuffleRect

                anchors.fill: parent
                color: "transparent"

                Image {
                    id: shuffleImg

                    width: 32
                    height: 32
                    anchors.centerIn: parent
                    source: `Resources/shuffle-button.png`
                    fillMode: Image.PreserveAspectFit
                }
            }
        }

        Item {
            id: previousItem

            Layout.fillWidth: true
            Layout.fillHeight: true

            Rectangle {
                id: previousRect

                anchors.fill: parent
                color: "transparent"

                Image {
                    id: previousImg

                    width: 32
                    height: 32
                    anchors.centerIn: parent
                    source: `Resources/previous-button.png`
                    fillMode: Image.PreserveAspectFit
                }
            }
        }

        Item {
            id: playPauseItem

            Layout.fillWidth: true
            Layout.fillHeight: true

            Rectangle {
                id: playPauseRect

                anchors.fill: parent
                color: "transparent"

                Image {
                    id: playPauseImg

                    width: 48
                    height: 48
                    anchors.centerIn: parent
                    source: `Resources/play-button.png`
                    fillMode: Image.PreserveAspectFit
                }
            }
        }

        Item {
            id: nextItem

            Layout.fillWidth: true
            Layout.fillHeight: true

            Rectangle {
                id: nextRect

                anchors.fill: parent
                color: "transparent"

                Image {
                    id: nextImg

                    width: 32
                    height: 32
                    anchors.centerIn: parent
                    source: `Resources/next-button.png`
                    fillMode: Image.PreserveAspectFit
                }
            }
        }

        Item {
            id: repeatItem

            Layout.fillWidth: true
            Layout.fillHeight: true

            Rectangle {
                id: repeatRect

                anchors.fill: parent
                color: "transparent"

                Image {
                    id: repeatImg

                    width: 32
                    height: 32
                    anchors.centerIn: parent
                    source: `Resources/repeat-button.png`
                    fillMode: Image.PreserveAspectFit
                }
            }
        }
    }
}