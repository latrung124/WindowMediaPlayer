import QtQuick
import QtQuick.Controls

pragma Singleton

ApplicationWindow {
    id: root

    objectName: "AppWindow"
    visible: true
    width: 1366
    height: 780
    title: qsTr("Media Player")
    color: "transparent"
    flags: Qt.FramelessWindowHint | Qt.Window

    Component.onCompleted: function() {
        x = (screen.width - width) / 2;
        y = (screen.height - height) / 2;
    }

    Rectangle {
        id: backgroundRect

        anchors.fill: parent
        color: "#000000"
        opacity: 1
        radius: 8

        border.color: "#ffffff"
        border.width: 0.5
    }

    WindowControl {
        id: windowControl

        anchors {
            top: parent.top
            topMargin: 10
            right: parent.right
            rightMargin: 5
        }

        onCloseWindowClicked: {
            root.close();
            if (windowController) {
                windowController.closeWindow();
            }
        }
    }

    MainContent {
        id: mainContent

        anchors {
            top: parent.top
            topMargin: 80
            left: parent.left
            leftMargin: 10
            right: parent.right
            rightMargin: 10
        }
    }

    BottomMediaPlayer {
        id: bottomMediaPlayer
        objectName: "bottomMediaPlayer"

        anchors {
            bottom: parent.bottom
            top: mainContent.bottom
            topMargin: 10
            left: parent.left
            right: parent.right
        }
    }
}
