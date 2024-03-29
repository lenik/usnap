
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

function inside(convex, pt, radius) {
    var eps = 1e-3;
    var center = shapeCenter(convex);
    var max = polygonArea(convex, center) + eps;
    if (radius === undefined) {
        return polygonArea(convex, pt) > max;
    }
    var pts = [
                new Point(pt.x - radius, pt.y),
                new Point(pt.x + radius, pt.y),
                new Point(pt.x, pt.y - radius),
                new Point(pt.x, pt.y + radius)
            ];
    for (var i = 0; i < pts.length; i++) {
        if (polygonArea(convex, pts[i]) < max)
            return true;
    }
    return false;
}

function lineIntr(s1, e1, s2, e2, within) {
    var eps = 1e-5;
    var w1 = e1.x - s1.x, h1 = e1.y - s1.y;
    var w2 = e2.x - s2.x, h2 = e2.y - s2.y;
    var m = w1 * h2 - w2 * h1;
    if (Math.abs(m) < eps) return null;

    var pt = new Point();
    pt.x = ((s2.x*e2.y - s2.y*e2.x)*w1 - (s1.x*e1.y - s1.y*e1.x)*w2) / m;
    pt.y = ((s2.x*e2.y - s2.y*e2.x)*h1 - (s1.x*e1.y - s1.y*e1.x)*h2) / m;

    if (within) {
        var u = (pt.x - s1.x) / (s2.x - s1.x);
        var v = (pt.y - s1.y) / (s2.y - s1.y);
        var uValid = u >= 0 && u <= 1;
        var vValid = v >= 0 && v <= 1;
        if (! (uValid || vValid))
            return null;

        u = (pt.x - s2.x) / (s2.x - s1.x);
        v = (pt.y - s2.y) / (s2.y - s1.y);
        uValid = u >= 0;
        vValid = v >= 0;
        if (! (uValid || vValid))
            return null;
    }
    return pt;
}

function polygonIntr(polygon, src, dst) {
    for (var a = 0; a < polygon.length; a++) {
        var b = (a + 1) % polygon.length;
        var pt = lineIntr(polygon[a], polygon[b], src, dst, true);
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

function sign(x) {
    if (x === 0)
        return 0;
    else if (x > 0)
        return 1;
    else
        return -1;
}

function bounceTowards(lineA, lineB, pt, addDelta) {
    var s = side(lineA, lineB, pt);
    s = sign(-s);
    var a = s * Math.PI / 4;

    var dx = lineB.x - lineA.x;
    var dy = lineB.y - lineA.y;

    if (addDelta !== undefined) {
        var len = Math.sqrt(dx * dx + dy * dy);
        var k = 1 + addDelta / len;
        dx *= k;
        dy *= k;
    }

    var vx = dx * Math.cos(a) - dy * Math.sin(a);
    var vy = dx * Math.sin(a) + dy * Math.cos(a);

    var end = new Point(
                pt.x + vx,
                pt.y + vy);
    return end;
}

function bounceTarget(polygon, lineA, lineB, pt, g) {
    var towards = bounceTowards(lineA, lineB, pt);
    var end = polygonIntr(polygon, pt, towards);
    if (end === null) {
        if (g !== undefined)
            g.drawLine(pt.x, pt.y, towards.x, towards.y, "green");
        return null; // unexpected?
    } else {
        if (g !== undefined) {
            g.drawLine(pt.x, pt.y, towards.x, towards.y, "blue");
            g.drawLine(pt.x, pt.y, end.x, end.y, "red");
        }
    }
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

    end.x += ex * edgeK; // + (Math.random() - 0.5) * 0.5;
    end.y += ey * edgeK; // + (Math.random() - 0.5) * 0.5;

    return end;
}

function moveTarget(polygon, lineA, lineB, pt) {
    var margin = 2;
    var dx = lineB.x - lineA.x;
    var dy = lineB.y - lineA.y;
    var lineLen = Math.sqrt(dx * dx + dy * dy);
    var scale = Math.pow(lineLen, 0.3); // Math.sqrt(lineLen);
    var tx = pt.x + dx / scale + (Math.random() - 0.5) * 0.5;
    var ty = pt.y + dy / scale + (Math.random() - 0.5) * 0.5;

    if (tx < margin) tx = margin;
    if (ty < margin) ty = margin;
    if (tx >= 100 - margin) tx = 100 - margin;
    if (ty >= 100 - margin) ty = 100 - margin;
    return new Geom.Point(tx, ty);
}

function Graph(ctx, xScale, yScale, width, height) {
    this.ctx = ctx;
    this.xScale = xScale;
    this.yScale = yScale;
    this.width = width;
    this.height = height;

    this.clear = function() {
         ctx.clearRect(0, 0, width * xScale, height * yScale);
     };

    this.drawPixel = function(x, y, color) {
        if (color !== undefined)
            ctx.fillStyle = color;
        ctx.beginPath();
        ctx.fillRect(x, y, 1, 1);
        ctx.closePath();
    };

    this.drawLine = function(x0, y0, x1, y1, color) {
        if (color !== undefined)
            ctx.strokeStyle = color;
        ctx.beginPath();
        ctx.moveTo(x0 * xScale, y0 * yScale);
        ctx.lineTo(x1 * xScale, y1 * yScale);
        ctx.closePath();
        ctx.stroke();
    };

    this.drawCircle = function(x, y, radius, strokeColor, fillColor) {
        if (fillColor !== undefined)
            ctx.fillStyle = fillColor;
        if (strokeColor !== undefined)
            ctx.strokeStyle = strokeColor;
        ctx.beginPath();
        ctx.arc(x * xScale, y * yScale, radius * xScale, 0, Math.PI * 2, true);
        ctx.closePath();
        if (fillColor !== undefined)
            ctx.fill();
        ctx.stroke();
    };

    this.drawPolygon = function(polygon, strokeColor, fillColor) {
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
    };
}
