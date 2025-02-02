/*
* BottomMediaPlayer.qml
* Author: trung.la
* Date: 01-03-2025
* Description: This file contains the bottom media player of the application
*/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Qt5Compat.GraphicalEffects

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
                    anchors.centerIn: parent
                    source: mediaPlayerModel ? (mediaPlayerModel.thumbnail === "" ? internal.musicNote : mediaPlayerModel.thumbnail) : internal.musicNote
                    fillMode: Image.PreserveAspectFit
                    cache: false
                    layer.enabled: true
                    layer.effect: OpacityMask {
                        maskSource: Item {
                            width: albumArt.width
                            height: albumArt.height
                            Rectangle {
                                anchors.centerIn: parent
                                width: albumArt.width
                                height: albumArt.height
                                radius: 4
                            }
                        }
                    }
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

        ColumnLayout {
            id: controlColumnLayout

            Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
            Layout.fillWidth: true
            Layout.fillHeight: true
            spacing: 0

            MediaControl {
                id: mediaControl

                Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
                isPlaying: mediaPlayerModel ? mediaPlayerModel.isPlaying : false
                isPlayingEnabled: mediaPlayerModel ? mediaPlayerModel.isPlayingEnabled : false
                isPauseEnabled: mediaPlayerModel ? mediaPlayerModel.isPauseEnabled : false
                isShuffleEnabled: mediaPlayerModel ? mediaPlayerModel.isShuffleEnabled : false
                isRepeatEnabled: mediaPlayerModel ? mediaPlayerModel.isRepeatEnabled : false
                isPreviousEnabled: mediaPlayerModel ? mediaPlayerModel.isPreviousEnabled : false
                isNextEnabled: mediaPlayerModel ? mediaPlayerModel.isNextEnabled : false
            }

            RowLayout {
                id: progressRowLayout

                Layout.preferredWidth: 600
                Layout.preferredHeight: 20
                Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
                Item {
                    id: startTimeRect

                    Layout.preferredWidth: 20
                    Layout.preferredHeight: 20

                    Text {
                        id: startTimeText

                        anchors.fill: parent
                        horizontalAlignment: Text.AlignRight
                        verticalAlignment: Text.AlignVCenter
                        text: mediaPlayerModel ? mediaPlayerModel.startTime : "00:00"
                        font {
                            family: "Helvetica"
                            pixelSize: 12
                        }
                        color: "#FFFFFF"
                    }
                }

                Rectangle {
                    id: durationRect

                    Layout.preferredWidth: 560
                    Layout.preferredHeight: 4
                    Layout.alignment: Qt.AlignVCenter
                    color: "#999999"
                    radius: 2

                    Rectangle {
                        id: progressRect

                        width: mediaPlayerModel ? mediaPlayerModel.position * (durationRect.width/100) : 0
                        height: 4
                        color: "#FFFFFF"
                        radius: 2
                    }
                }

                Item {
                    id: endTimeRect

                    Layout.preferredWidth: 20
                    Layout.preferredHeight: 20

                    Text {
                        id: endTimeText

                        anchors.fill: parent
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                        text: mediaPlayerModel ? mediaPlayerModel.endTime : "00:00"
                        font {
                            family: "Helvetica"
                            pixelSize: 12
                        }
                        color: "#FFFFFF"
                    }
                }
            }
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
        readonly property string musicNote: `Resources/music-note.png`
    }
}
