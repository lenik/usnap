import QtQuick 1.1
import "../shared"

import "Geom.js" as Geom
import "Game.js" as Game
import "Room.js" as RoomModel;

Image {
    property int shapeIndex: 0
    property int shapeCount: RoomModel.sources.length
    property alias items: _items

    signal started
    signal removed

    id: room

    source: "images/" + RoomModel.sources[shapeIndex];
    fillMode: Image.PreserveAspectFit

    Item {
        id: _items
        width: parent.width
        height: parent.height
    }

    MouseArea {
        anchors.fill: parent
        onPressed: {
            broom.setCenterXY(mouseX, mouseY);
            broom.visible = true;
        }
        onReleased: {
            broom.visible = false;
        }
        onPositionChanged: {
            if (! broom.visible)
                return;

            var startU = broom.u;
            var startV = broom.v;

            broom.setCenterXY(mouseX, mouseY);
            var endU = broom.u;
            var endV = broom.v;

//                    var du = endU - startU;
//                    var dv = endV - startV;

            var head = broom.getShape();
            var startShape = [];
            var endShape = [];
            for (var i = 0; i < head.length; i++) {
                var pt = head[i];
                startShape[i] = new Geom.Point(pt.x + startU, pt.y + startV);
                endShape[i] = new Geom.Point(pt.x + endU, pt.y + endV);
            }

            var convex = Geom.convex(startShape.concat(endShape));

            // var ctx = canvas.getContext();
            // ctx.clearRect(0, 0, canvas.width, canvas.height);
            // Game.drawPolygon(ctx, convex, canvas.width/100, canvas.height/100, "red", "pink");

            var pts = Game.level.points;
            var hits = [];
            var nhit = 0;
            for (i = 0; i < pts.length; i++) {
                pt = pts[i];
                if (Geom.inside(convex, pt))
                    hits[nhit++] = pt;
            }

            for (i = 0; i < nhit; i++) {
                pt = hits[i];
                var item = pt.item;
                var target = Geom.moveTarget(convex,
                                  new Geom.Point(startU, startV),
                                  new Geom.Point(endU, endV),
                                  pt);
                if (target === null) continue;
                pt.x = target.x;
                pt.y = target.y;
                item.u = pt.x;
                item.v = pt.y;
            }
        } // onPositionChanged
    }

    Broom {
        id: broom
        visible: false
        z: 10
    }

}
