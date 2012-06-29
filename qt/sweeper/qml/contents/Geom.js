
function Point(_x, _y) {
    this.x = _x;
    this.y = _y;
}

function Vector(_x, _y) {
    this.x = _x;
    this.y = _y;
}

function LineSeg(_src, _dst) {
    this.src = _src;
    this.dst = _dst;
    this.len = function() {
             var dx = dst.x - src.x;
             var dy = dst.y - src.y;
            return Math.sqrt(dx * dx + dy * dy);
         };
}

function Rectangle(p1, p2) {
    this.topLeft = new Point(
             Math.min(p1.x, p2.x), Math.min(p1.y, p2.y));
    this.bottomRight = new Point(
             Math.max(p1.x, p2.x), Math.max(p1.y, p2.y));
    this.width = function() {
             return bottomRight.x - topLeft.x;
         };
    this.height = function() {
             return bottomRight.y - topLeft.y;
         };
    this.area = function() {
             return width() * height();
         };
}

/**
 * @return 0  parallel
 *         >0 ccw, or turn-left
 *         <0 cw, or turn-right
 */
function ccw(o, p, q) {
    return (p.x - o.x) * (q.y - o.y) - (p.y - o.y) * (q.x - o.x);
}

/**
 * @return =0 on the line
 *         <0 left-side
 *         >0 right-side
 */
function side(lineA, lineB, pt) {
    return -ccw(lineA, lineB, pt);
}

function cos_angle(x, y) {
    var len = Math.sqrt(x * x + y * y);
    if (len == 0)
        return 1; // cos 0' == 1.
    else
        return x / len;
}

function convex_presort(points) {
    var minX = points[0].x;
    var minY = points[0].y;
    var minIndex = 0;
    for (var i = 1; i < points.length; i++) {
        var pt = points[i];
        if (pt.y < minY) {
            minX = pt.x;
            minY = pt.y;
            minIndex = i;
        } else if (pt.y === minY) {
            if (pt.x < minX) {
                minX = pt.x;
             // minY = pt.y;
                minIndex = i;
            }
        }
    }
    if (minIndex != 0) { // bring to the first.
        var t = points[minIndex];
        points[minIndex] = points[0];
        points[0] = t;
    }

    var base = points[0];
    points.sort(function(p1, p2) {
        var a1 = cos_angle(p1.x - base.x, p1.y - base.y);
        var a2 = cos_angle(p2.x - base.x, p2.y - base.y);
        return -(a1 - a2);
    });
}

function convex(points) {
    convex_presort(points);
    // var end = points[points.length - 1];
    var stack = [ points[0], points[1] ];
    var n = stack.length;
    for (var i = n; i < points.length; i++) {
        stack[n++] = points[i];
        // reduce
        while (n >= 3) {
            if (ccw(stack[n-3], stack[n-2], stack[n-1]) <= 0) {
                stack[n-2] = stack[n-1];
                n--;
            } else {
                break;
            }
        }
    }
    stack.splice(n);
    return stack;
}

function shapeCenter(points) {
    var sumX = 0;
    var sumY = 0;
    for (var i = 0; i < points.length; i++) {
        sumX += points[i].x;
        sumY += points[i].y;
    }
    var center = new Point(
            sumX / points.length,
            sumY / points.length);
    return center;
}

function dist(p, q) {
    var dx = q.x - p.x;
    var dy = q.y - p.y;
    return Math.sqrt(dx * dx + dy * dy);
}

function triangleArea(p, q, r) {
    var a = dist(p, q);
    var b = dist(q, r);
    var c = dist(r, p);
    var s = (a + b + c) / 2;
    var area = Math.sqrt(s * (s - a) * (s - b) * (s - c));
    return area;
}

function polygonArea(polygon, hint) {
    var area = 0;
    for (var i = 0; i < polygon.length; i++) {
        var prev = i - 1;
        if (prev < 0) prev = polygon.length - 1;
        area += triangleArea(polygon[prev], polygon[i], hint);
    }
    return area;
}

function inside(convex, pt) {
    var eps = 10;
    var center = shapeCenter(convex);
    var expected = polygonArea(convex, center);
    var actual = polygonArea(convex, pt);
    return Math.abs(expected - actual) < eps;
}

function lineIntr(p1, p2, q1, q2, limited) {
    var dpx = p2.x - p1.x;
    var dpy = p2.y - p1.y;
    var dqx = q2.x - q1.x;
    var dqy = q2.y - q1.y;
    var m = dpx * dqy - dqx * dpy;
    var u = dqx * (p1.y - q1.y) - dqy * (p1.x - q1.x);
    var v = dpx * (p1.y - q1.y) - dpy * (p1.x - q1.x);
    if (limited) {
        if (u < 0 || u > 1)
            return null;
        if (v < 0 || v > 1)
            return null;
    }
    var pt = new Point();
    pt.x = p1.x + u * dpx;
    pt.y = p1.y + v * dpy;
    return pt;
}

function polygonIntr(polygon, p, q) {
    for (var i = 1; i < polygon.length; i++) {
        var pt = lineIntr(polygon[i - 1], polygon[i], p, q, true);
        if (pt !== null)
            return pt;
    }
    return null;
}

function boundingBox(points) {
    var minX = points[0].x;
    var minY = points[0].y;
    var maxX = maxX;
    var maxY = maxY;
    for (var i = 1; i < points.length; i++) {
        var pt = points[i];
        if (pt.x < minX) minX = pt.x;
        if (pt.x > maxX) maxX = pt.x;
        if (pt.y < minY) minY = pt.y;
        if (pt.y > maxY) maxY = pt.y;
    }
    var box = new Rectangle(
                new Point(minX, minY),
                new Point(maxX, maxY));
    return box;
}

function centerScale(points, delta) {
    var center = shapeCenter(points);
    var bbox = boundingBox(points);
    var size = Math.max(bbox.width(), bbox.height());
    var k = 1 + delta / size;
    for (var i = 0; i < points.length; i++) {
        var pt = points[i];
        pt.x = k * (pt.x - center.x) + center.x;
        pt.y = k * (pt.y - center.y) + center.y;
    }
}

function bounceFarEnd(lineA, lineB, pt, addDelta) {
    var s = side(lineA, lineB, pt);
    s = Math.sign(-s);
    var a = s * Math.PI / 4;

    var dx = lineB.x - lineA.x;
    var dy = lineB.y - lineA.y;
    var len = Math.sqrt(dx * dx + dy * dy);
    var k = 1 + addDelta / len;
    dx *= k;
    dy *= k;

    var vx = dx * cos(a) - dy * sin(a);
    var vy = dx * sin(a) + dy * cos(a);

    var end = new Point(
                pt.x + vx,
                pt.y + vy);
    return end;
}

function bounceTarget(polygon, lineA, lineB, pt) {
    var safeExtent = 30;
    var farEnd = bounceFarEnd(lineA, lineB, pt, safeExtent);
    var end = polygonIntr(polygon, pt, farEnd);
    if (end === null)
        return null; // unexpected?

    var ex = end.x - pt.x;
    var ey = end.y - pt.y;
    var endLen = Math.sqrt(ex * ex + ey * ey);

    var start = lineIntr(lineA, lineB, pt, end, false);
    // assert start != null;
    var sx = pt.x - start.x;
    var sy = pt.y - start.y;
    var startLen = Math.sqrt(sx * sx + sy * sy);

    var edgeK = endLen / (startLen + endLen);
    // var force = edgeK * edgeK;

    end.x += ex * edgeK + (Math.random() - 0.5) * 0.5;
    end.y += ey * edgeK + (Math.random() - 0.5) * 0.5;

    return end;
}
