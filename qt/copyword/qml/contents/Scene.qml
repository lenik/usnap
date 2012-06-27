import QtQuick 1.1
import "../shared"

BorderImage {
    property bool smallMode: Math.min(width, height) < 300
    property real scaleRatio: smallMode ? 0.5 : 1

    property alias title: titleText.text
    property alias color: titleText.color

    id: scene
    clip: true

    source: smallMode ? "images/sky-small.png" : "images/sky.png"
    border {
        left: 264 * scaleRatio
        right: 170 * scaleRatio
        top: 191 * scaleRatio
        bottom: 0 * scaleRatio
    }
    horizontalTileMode: BorderImage.Repeat
    verticalTileMode: BorderImage.Repeat

    Image {
        id: mountain
        source: smallMode ? "images/mountain-small.png" : "images/mountain.png"
        width: parent.width
        height: parent.height * 0.15
        anchors.bottom: parent.bottom
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
