import QtQuick 1.1
import "shared"
import "contents"

import "contents/Geom.js" as Geom

Rectangle {
    property bool debug: true

    id: screen

    width: debug ? 240 : 480
    height: debug ? 300 : 800

    function dist() {
        var JunkType = Qt.createComponent("contents/Junk.qml");

        var count = 10;
        for (var i = 0; i < count; i++) {
            var junk = JunkType.createObject(box);
            junk._x = Math.random() * 100;
            junk._y = Math.random() * 100;
        }
    }

    Rectangle {
        id: box
        width: parent.width
        height: parent.height
        //anchors.bottom: screen.bottom
        color: "lightgray"
    }

    ScriptAction {
        running: true
        script: dist();
    }

}
