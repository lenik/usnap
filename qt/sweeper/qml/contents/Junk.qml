import QtQuick 1.1
import "../shared"

import "Junk.js" as JunkModel;

Image {
    property real u
    property real v
    property real uWidth: 100
    property real uHeight: 100
    property int shapeIndex: 0
    property int shapeCount: JunkModel.sources.length
    property string text
    // property alias text: text1.text
    property bool marked
    property bool animated

    id: junk
    width: Math.max(parent.width, parent.height) / 20
    height: width

    x: parent.width * (u / uWidth) - width / 2
    y: parent.height * (v / uHeight) - height / 2

    source: "stuff/" + JunkModel.sources[shapeIndex];
    fillMode: Image.PreserveAspectFit
    smooth: true

    Behavior on x {
        NumberAnimation {
            duration: animated ? 300 : 0
            easing.type: Easing.OutQuad
        }
    }

    Behavior on y {
        NumberAnimation {
            duration: animated ? 300 : 0
            easing.type: Easing.OutQuad
        }
    }

    Text {
        id: text1
        anchors.centerIn: parent
        font.pixelSize: Math.min(parent.width, parent.height)
        color: "white"
    }

    Rectangle {
        id: marker
        x: 4
        y: 4
        width: parent.width - 8
        height: parent.height - 8
        radius: width / 2
        border.color: "red"
        border.width: 2
        visible: marked
    }

}
