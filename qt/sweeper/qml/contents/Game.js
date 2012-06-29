
var level = {
    points: [],
    convex: [],
};

function createLevel(parent) {
    var JunkType = Qt.createComponent("contents/Junk.qml");

    for (var i = 0; i < parent.children.length; i++) {
        var child = parent.children[i];
        if (child.toString().substr(0, 4) === "Junk")
            child.destroy();
    }

    var count = 10;
    var points = [];
    for (var i = 0; i < count; i++) {
        var junk = JunkType.createObject(parent);
        var pt = new Geom.Point();
        junk.u = pt.x = Math.random() * 100;
        junk.v = pt.y = Math.random() * 100;
        junk.shapeIndex = Math.floor(Math.random() * junk.shapeCount);
        junk.rotation = Math.random() * 360;
        junk.text = i;
        pt.item = junk;
        points[i] = pt;
    }

    level.points = points;
    level.convex = Geom.convex(points);

    var ctx = canvas.getContext();
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    drawPolygon(ctx, level.convex, canvas.width/100, canvas.height/100);
}

function drawPolygon(ctx, polygon, xScale, yScale, strokeColor, fillColor) {
    if (fillColor !== undefined)
        ctx.fillStyle = fillColor;
    if (strokeColor !== undefined)
        ctx.strokeStyle = strokeColor;
    ctx.beginPath();
    ctx.moveTo(
                polygon[0].x * xScale,
                polygon[0].y * yScale);
    for (var i = 1; i < polygon.length; i++)
        ctx.lineTo(
                    polygon[i].x * xScale,
                    polygon[i].y * yScale);
    ctx.closePath();
    ctx.stroke();
}

function drawCircle(ctx, x, y, radius, strokeColor, fillColor) {
    if (fillColor !== undefined)
        ctx.fillStyle = fillColor;
    if (strokeColor !== undefined)
        ctx.strokeStyle = strokeColor;
    ctx.beginPath();
    ctx.arc(x, y, radius, 0, Math.PI * 2, true);
    ctx.closePath();
    if (fillColor !== undefined)
        ctx.fill();
    ctx.stroke();
}

function drawPixel(ctx, x, y, color) {
    if (color !== undefined)
        ctx.fillStyle = color;
    ctx.beginPath();
    ctx.fillRect(x, y, 1, 1);
    ctx.closePath();
}

var broomPos = new Object();
