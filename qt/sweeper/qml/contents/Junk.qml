import QtQuick 1.1
import "../shared"

Rectangle {
    property real _x
    property real _y
    property real _width: 100
    property real _height: 100

    id: junk

    width: 10
    height: 10
    radius: 4

    x: parent.width * (_x / _width) - width / 2
    y: parent.height * (_y / _height) - height / 2

    color: "blue"
}
