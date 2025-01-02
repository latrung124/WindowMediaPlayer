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
    flags: Qt.FramelessWindowHint

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
    }

    WindowControl {
        id: windowControl

        anchors {
            top: parent.top
            topMargin: 10
            right: parent.right
            rightMargin: 5
        }
    }
}
