import QtQuick 1.1
import "../shared"

Item {
    property alias textText: content
    property alias text: content.text
    property alias font: content.font
    property alias textWidth: content.width
    property alias textHeight: content.height
    property alias textColor: content.color
    property alias background: bg.color

    id: item

    Rectangle {
        id: bg
        opacity: 0.5
        clip: true
        color: "black"
        anchors.fill: parent
    }

    Text {
        id: content
        width: parent.width * 0.95
        height: parent.height * 0.95
        anchors.fill: parent
        font.pixelSize: Math.min(item.width, item.height) / 20
        // Try h-flick instead.
        // wrapMode: Text.WordWrap
        color: "white"
    }
}
