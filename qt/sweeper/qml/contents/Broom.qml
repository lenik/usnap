import QtQuick 1.1
import "../shared"

import "Geom.js" as Geom;
import "Broom.js" as BroomModel;

Image {
    property real u
    property real v
    property real uWidth: 100
    property real uHeight: 100
    property alias text: text1.text

    id: broom
    source: "images/broom.png"
    mirror: u > uWidth / 2
    property real _baseX: BroomModel.broomBase.x / 100
    property real baseX: mirror ? (1 - _baseX) : _baseX
    property real baseY: BroomModel.broomBase.y / 100

    fillMode: Image.PreserveAspectFit
    width: parent.width * BroomModel.broomSpanX / 100
    x: parent.width * (u / uWidth) - width * baseX
    y: parent.height * (v / uHeight) - height * baseY

    function setCenterXY(x, y) {
        u = x / parent.width * uWidth;
        v = y / parent.height * uHeight;
    }

    function getCenterXY() {
        var center = new Geom.Point();
        center.x = u * parent.width / uWidth;
        center.y = v * parent.height / uHeight;
        return center;
    }

    function getShape() {
        var _shape = mirror ? BroomModel.broomShapeMirrored
                           : BroomModel.broomShape;
        var shape = [];
        for (var i = 0; i < _shape.length; i++) {
            var pt = _shape[i];
            shape[i] = new Geom.Point(pt.x, pt.y);
        }
        return shape;
    }

    Text {
        id: text1
        anchors.centerIn: parent
        font.pixelSize: Math.min(parent.width, parent.height)
        color: "white"
    }

    Component.onCompleted: BroomModel.init()
}
