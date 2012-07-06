
var data = {
    points: [],
    convex: [],
};

function createLevel(parent, level) {
    var JunkType = Qt.createComponent("Junk.qml");

    for (var i = 0; i < parent.children.length; i++) {
        var child = parent.children[i];
        if (child.toString().substr(0, 4) === "Junk")
            child.destroy();
    }

    var count = 2 + level * 3;
    var points = [];
    for (var i = 0; i < count; i++) {
        var junk = JunkType.createObject(parent);
        var pt = new Geom.Point();
        junk.u = pt.x = Math.random() * 100;
        junk.v = pt.y = Math.random() * 100;
        junk.shapeIndex = Math.floor(Math.random() * junk.shapeCount);
        junk.rotation = Math.random() * 360;
        junk.text = i;
        junk.animated = true;
        pt.item = junk;
        points[i] = pt;
    }

    data.points = points;
    data.convex = Geom.convex(points);

//    var ctx = canvas.getContext();
//    ctx.clearRect(0, 0, canvas.width, canvas.height);
//    Geom.drawPolygon(ctx, data.convex, canvas.width/100, canvas.height/100);
}

var broomPos = new Object();
