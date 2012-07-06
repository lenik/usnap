
function Point(_x, _y) {
    this.x = _x;
    this.y = _y;
}

var _width = 97;
var _height = 120;
var _outline = [
            70, 67,
            85, 89,
            80, 100,
            52, 102,
            20, 100,
            42, 83,
        ];
var _base = [ 55, 92 ];

var broomRealPart = 0.6;
var broomSpanX = (10 / broomRealPart);
var broomSpanY = broomSpanX * _height / _width;
var broomBase = new Object();
var broomShape = [];
var broomShapeMirrored = [];

function init() {
    broomBase = new Point();
    broomBase.x = 100 * _base[0] / _width;
    broomBase.y = 100 * _base[1] / _height;

    var count = 0;
    for (var i = 0; i < _outline.length; i += 2) {
        var _x = _outline[i] - _base[0];
        var _y = _outline[i+1] - _base[1];
        var _xMirror = -_x; // + (_base[0] - _x) * 2;

        broomShape[count] = new Point(
                    broomSpanX * _x / _width,
                    broomSpanY * _y / _height);

        broomShapeMirrored[count] = new Point(
                    broomSpanX * _xMirror / _width,
                    broomSpanY * _y / _height);
        count++;
    }
}

init();
