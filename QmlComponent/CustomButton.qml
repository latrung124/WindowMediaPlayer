/*
* CustomButton.qml
* Author: trung.la
* Date: 01-04-2025
* Brief: This file contains the CustomButton component which is used to create a custom button.
*/

import QtQuick
import QtQuick.Controls
import QtQuick.Templates as T
import Qt5Compat.GraphicalEffects

T.Button {
    id: control

    property string iconSource: ""
    property color iconColor: "#ffffff"

    property alias isShowIcon: background.isShowIcon
    property alias isShowBackground: background.isShowBackground

    implicitWidth: Math.max(background.implicitWidth + leftInset + rightInset,
                            contentItem.implicitWidth + leftPadding + rightPadding)
    implicitHeight: Math.max(background.implicitHeight + topInset + bottomInset,
                            contentItem.implicitHeight + topPadding + bottomPadding)

    font.family: "Helvetica"
    font.pixelSize: 16

    contentItem: CustomButtonContent {
        id: contentItem

        text: control.text
        font: control.font
    }

    background: CustomButtonBackground {
        id: background

        iconSource: control.iconSource
        iconColor: control.iconColor
    }
}