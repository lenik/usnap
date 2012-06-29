import QtQuick 1.1
import "../shared"

Rectangle {
    property real _x
    property real _y
    property real _width: 100
    property real _height: 100
    property alias text: text1.text

    id: junk

    width: 20
    height: 20
    radius: 8

    x: parent.width * (_x / _width) - width / 2
    y: parent.height * (_y / _height) - height / 2

    color: "blue"

    Text {
        id: text1
        anchors.centerIn: parent
        font.pixelSize: Math.min(parent.width, parent.height)
        color: "white"
    }

}
