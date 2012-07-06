import QtQuick 1.1
// import QtMultimediaKit 1.1
// import Qt.labs.Canvas 1.0
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
    smooth: true
    fillMode: Image.Stretch
    // color: "#f0f0cc"

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

            // piano.play();
            var f0 = new Geom.Point(broom.u, broom.v);
            broom.setCenterXY(mouseX, mouseY);
            var f1 = new Geom.Point(broom.u, broom.v);
            // var du = f1.x - f0.x;
            // var dv = f1.y - f0.y;

            var head = broom.getShape();
            var startShape = [];
            var endShape = [];
            for (var i = 0; i < head.length; i++) {
                var pt = head[i];
                startShape[i] = new Geom.Point(pt.x + f0.x, pt.y + f0.y);
                endShape[i] = new Geom.Point(pt.x + f1.x, pt.y + f1.y);
            }

            var convex = Geom.convex(startShape.concat(endShape));

            // var ctx = room.getContext();
            // var g = new Geom.Graph(ctx, room.width / 100, room.height / 100, 100, 100);
            // if (RoomModel.moveCount++ % 30 === 0) g.clear();
            // g.drawPolygon(convex, "lightgray");
            // g.drawLine(startU, startV, endU, endV, "pink");

            var pts = Game.data.points;
            var hits = [];
            var nhit = 0;
            var item;
            for (i = 0; i < pts.length; i++) {
                pt = pts[i];
                item = pt.item;
                var radius = item.radius / room.width * 100;
                if (Geom.inside(convex, pt, radius * 0.7))
                    hits[nhit++] = pt;
            }

            for (i = 0; i < nhit; i++) {
                pt = hits[i];
                item = pt.item;
                if (! item.visible) // Don't move hidden junk.
                    continue;
                // g.drawCircle(pt.x, pt.y, 3, "black");
                var target = Geom.moveTarget(convex,
                                  f0,f1, pt);
                if (target === null) continue;
                pt.x = target.x;
                pt.y = target.y;
                item.u = pt.x;
                item.v = pt.y;

                var side = Geom.side(f0, f1, pt);
                item.rotation += -side * (Math.random() * 5);

                if (trash.overlapped(item)) {
                    item.visible = false;
                    room.removed(item);
                }
            }
        } // onPositionChanged
    }

    Broom {
        id: broom
        visible: false
        z: 10
    }

    Image {
        id: trash
        source: "images/trash.svg"
        width: parent.width / 10
        height: parent.height / 10
        fillMode: Image.PreserveAspectFit
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
