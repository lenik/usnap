import QtQuick 1.1
import Qt.labs.Canvas 1.0
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
        width: 100
        height: 30
        text: "Refresh"
        onClicked: Game.createLevel(canvas)
    }
    Context2D { id: c }
    Canvas {
        id: canvas
        y: 100
        width: parent.width
        height: parent.height - 100
        //anchors.bottom: screen.bottom
        color: "gray"
        onPaint: {
        }
    }

    Junk {
        id: hintM
        width: 10
        height: 10
        radius: 4
        color: "pink"
    }
    Junk {
        id: hintI
        width: 10
        height: 10
        radius: 4
        color: "red"
    }

}
