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
            id: mediaInfoItem

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

            Item {
                id: songInfoItem

                width: 120
                height: 40
                anchors {
                    verticalCenter: parent.verticalCenter
                    left: albumArtRect.right
                    leftMargin: 4
                }

                ColumnLayout {
                    id: songInfoLayout

                    anchors.fill: parent
                    spacing: 0

                    Item {
                        id: titleItem

                        Layout.fillWidth: true
                        Layout.fillHeight: true

                        Text {
                            id: titleText

                            text: qsTr("Hello World!")
                            font {
                                family: "Helvetica"
                                pixelSize: 16
                            }
                            anchors.centerIn: parent
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "#FFFFFF"
                        }
                    }

                    Item {
                        id: artistItem

                        Layout.fillWidth: true
                        Layout.fillHeight: true

                        Text {
                            id: artistText

                            text: qsTr("Im Trung!")
                            font {
                                family: "Helvetica"
                                pixelSize: 14
                            }
                            anchors.centerIn: parent
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "#888888"
                        }
                    }
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
