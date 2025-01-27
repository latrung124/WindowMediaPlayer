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

    property QtObject mediaPlayerModel: null

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
                color: "transparent"
                border {
                    width: 1
                    color: "#FFFFFF"
                }
                radius: 4
                Image {
                    id: albumArt

                    width: parent.width - 2
                    height: parent.height - 2
                    source: `Resources/music-note.png`
                    fillMode: Image.PreserveAspectFit
                }
            }

            Item {
                id: songInfoItem

                width: 200
                height: 40
                anchors {
                    verticalCenter: parent.verticalCenter
                    left: albumArtRect.right
                    leftMargin: 15
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

                            anchors.fill: parent
                            horizontalAlignment: Text.AlignLeft
                            verticalAlignment: Text.AlignVCenter
                            text: mediaPlayerModel ? mediaPlayerModel.title : ""
                            font {
                                family: "Helvetica"
                                pixelSize: 16
                            }
                            color: "#FFFFFF"
                            maximumLineCount: 1
                            elide: Text.ElideRight
                        }
                    }

                    Item {
                        id: artistItem

                        Layout.fillWidth: true
                        Layout.fillHeight: true

                        Text {
                            id: artistText

                            anchors.fill: parent
                            horizontalAlignment: Text.AlignLeft
                            verticalAlignment: Text.AlignVCenter
                            text: mediaPlayerModel ? mediaPlayerModel.artist : ""
                            font {
                                family: "Helvetica"
                                pixelSize: 14
                            }
                            color: "#888888"
                            maximumLineCount: 1
                            elide: Text.ElideRight
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
