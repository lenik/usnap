import QtQuick 1.1
import "../shared"

BorderImage {
    property bool smallMode: Math.min(width, height) < 300
    property real scaleRatio: smallMode ? 0.5 : 1
    property string topStyle
    property string bottomStyle

    property alias title: titleText.text
    property alias titleFont: titleText.font
    property alias color: titleText.color
    property alias bottomImage: mountain

    id: scene
    clip: true

    source: topStyle == "" ? "" : ("images/" + topStyle + (smallMode ? "-small" : "") + ".png")
    horizontalTileMode: BorderImage.Repeat
    verticalTileMode: BorderImage.Repeat

    Image {
        id: mountain
        source: bottomStyle == "" ? "" : ("images/" + bottomStyle + (smallMode ? "-small" : "") + ".png")
        width: parent.width
        anchors.bottom: parent.bottom
    }

    Text {
        id: titleText
        color: "white"
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.top: parent.top
        anchors.topMargin: 10
        // font.family: "Comic Sans MS"
        font.pixelSize: Math.min(scene.width, scene.height) / 10
    }

}
