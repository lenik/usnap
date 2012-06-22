import QtQuick 1.1

// The limitation is:
//      You need to create a custom item to be inserted 3x3 times
//      in the infinite flickable contents.

Flickable {
    property int rows: 3
    property int columns: 3
    property int origRow: 1
    property int origColumn: 1
    property bool aligned: false

    signal scrollLeft
    signal scrollRight
    signal scrollUp
    signal scrollDown
    signal positionChanged(int dx, int dy)

    id: grid

    contentWidth: width * columns
    contentHeight: height * rows
    contentX: width * origRow
    contentY: height * origColumn

    onFlickEnded: {
        var col = Math.round(contentX / width);
        var row = Math.round(contentY / height);
        // if (aligned)
        console.debug("row=" + row + ", col=" + col);
        if (row < origRow)
            grid.scrollUp();
        if (row > origRow)
            grid.scrollDown();
        if (col < origColumn)
            grid.scrollLeft();
        if (col > origColumn)
            grid.scrollRight();

        var dy = row - origRow;
        var dx = col - origColumn;
        grid.positionChanged(dx, dy);

        contentX = origColumn * width;
        contentY = origRow * height;
    }

}
