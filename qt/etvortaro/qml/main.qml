import QtQuick 1.1
import "shared"
import "contents"

Rectangle {
    id: screen

    property int cx
    property int cy

    width: 360
    height: 360

    Text {
        id: str
    }

    InfiniteFlickable {
        id: panel

        y: 100
        width: 200
        height: 100
        rows: 3
        columns: 3
        origRow: 1
        origColumn: 1
        clip: true

        Rectangle {
            id: rect1
            radius: 20
            width: panel.width
            height: panel.height
            color: "red"
        }
        Rectangle {
            id: rect2
            radius: 20
            width: panel.width
            height: panel.height
            color: "green"
            anchors.left: rect1.right
        }

        onPositionChanged: {
            cx += dx;
            cy += dy;
            str.text = "Position: x=" + cx + ", y=" + cy + "(Last: " + dx+"," + dy+")";
        }
    }

}
