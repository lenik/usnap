
var level = {
    points: [],
    convex: [],
};

function createLevel(parent) {
    var JunkType = Qt.createComponent("contents/Junk.qml");

    for (var i = 0; i < parent.children.length; i++) {
        var child = parent.children[i];
        child.destroy();
    }

    var count = 10;
    var points = [];
    for (var i = 0; i < count; i++) {
        var junk = JunkType.createObject(parent);
        var pt = new Geom.Point();
        pt.item = junk;
        junk._x = pt.x = Math.random() * 100;
        junk._y = pt.y = Math.random() * 100;
        points[i] = pt;
        junk.text = i;
    }

    level.convex = Geom.convex(points);

    var ctx = canvas.getContext();
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    drawPolygon(ctx, level.convex, canvas.width / 100, canvas.height / 100);
    for (var i = 0; i < level.convex.length; i++) {
        var it = level.convex[i].item;
        it.color = "green";
        it.text = i;
    }

    var center = Geom.shapeCenter(level.convex);
    drawCircle(ctx,
               center.x * canvas.width / 100,
               center.y * canvas.height / 100,
               10,"pink");
}

function drawPolygon(ctx, polygon, xScale, yScale) {
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
