import QtQuick 1.1
import "../shared"

Rectangle {
    property string text: content.text
    id: box
    opacity: 0.2
    clip: true
    color: "gray"

    Text {
        id: content
        width: parent.width * 0.95
        height: parent.height * 0.95
        anchors.fill: parent
    }

}
