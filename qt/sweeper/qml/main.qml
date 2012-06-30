import QtQuick 1.1
// import Qt.multimedia 1.0
import "shared"
import "contents"

import "contents/Geom.js" as Geom
import "contents/Game.js" as Game

Rectangle {
    property bool debug: true

    id: screen

    width: debug ? 320 : 480
    height: debug ? 500 : 800

    CoolButton {
        id: refresh
        anchors.horizontalCenter: parent.horizontalCenter
        width: 100
        height: 30
        text: "Refresh"
        onClicked: Game.createLevel(canvas)
    }

    Room {
        y: 40
        width: parent.width
        height: parent.height - 40
    }

    GameStatus {
        id: status
        z: 100
        anchors.fill: parent
    }

}
