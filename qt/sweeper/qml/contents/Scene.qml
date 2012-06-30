import QtQuick 1.1
import "../shared"

Rectangle {
    property alias title: titleText.text
    property alias color: titleText.color

    id: scene
    clip: true

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
