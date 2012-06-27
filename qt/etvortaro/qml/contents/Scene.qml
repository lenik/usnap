import QtQuick 1.1
import "../shared"

Item {
    property alias title: titleText.text
    property alias color: titleText.color

    id: scene
    clip: true

    BorderImage {
        id: background
        anchors.fill: parent
        source: "images/stars.png"
        border { left: 0; top: 0; right: 0; bottom: 0 }
        horizontalTileMode: BorderImage.Repeat
        verticalTileMode: BorderImage.Repeat
        // opacity: 0.8
    }

    Text {
        id: titleText
        color: "white"
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.top: parent.top
        anchors.topMargin: 10
        font.family: "Comic Sans MS"
        font.pixelSize: Math.min(scene.width, scene.height) / 10
    }

}
