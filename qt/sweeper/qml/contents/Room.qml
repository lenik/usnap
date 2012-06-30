import QtQuick 1.1
import "../shared"

import "Geom.js" as Geom
import "Game.js" as Game
import "Room.js" as RoomModel;

Image {
    property int shapeIndex: 0
    property int shapeCount: RoomModel.sources.length
    property alias items: _items
    property real posX
    property real posY

    signal removed(variant item)

    id: room

    source: "images/" + RoomModel.sources[shapeIndex];
    fillMode: Image.Stretch

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
            posX = mouseX;
            posY = mouseY;
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

            var pts = Game.data.points;
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
                if (! item.visible) // Don't move hidden junk.
                    continue;
                var target = Geom.moveTarget(convex,
                                  new Geom.Point(startU, startV),
                                  new Geom.Point(endU, endV),
                                  pt);
                if (target === null) continue;
                pt.x = target.x;
                pt.y = target.y;
                item.u = pt.x;
                item.v = pt.y;
                if (trash.overlapped(item)) {
                    item.visible = false;
                    room.removed(item);
                }
            }
        } // onPositionChanged
    }

    Image {
        id: trash
        source: "images/trash.svg"
        width: 30
        height: 40
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.rightMargin: 40
        anchors.bottomMargin: 20
        z: 5

        function overlapped(obj) {
            var centerX = x + width / 2;
            var centerY = y + height / 2;
            var objX = obj.x + obj.width / 2;
            var objY = obj.y + obj.height / 2;
            var dx = objX - centerX;
            var dy = objY - centerY;
            return Math.abs(dx) < width / 2
                    && Math.abs(dy) < height / 2;
        }
    }

    Broom {
        id: broom
        visible: false
        z: 10
    }

    function createLevel(level) {
        Game.createLevel(_items, level);
        console.log("Created: " + Game.data.points.length);
    }

    function getRemainingJunks() {
        var count = 0;
        for (var i = 0; i < _items.children.length; i++) {
            var child = _items.children[i];
            if (child.toString().substr(0, 4) === "Junk") {
                if (child.visible)
                    count++;
            }
        }
        return count;
    }

}
