import QtQuick 1.1
import "../shared"

Scene {
    property string fromSymbol
    property string toSymbol
    property variant dict

    property real listHeight: height - topHr.bottom
    property real fontSize: Math.min(width, listHeight) / 15
    property int pageSize: Math.max(width, listHeight) / (fontSize * 1.4)
    property int index: 0

    property alias text: queryText.text

    signal indicatorClicked
    signal closed

    id: lookup

    Item {
        id: navbar
        width: parent.width
        height: fromButton.height
        SymbolButton {
            id: fromButton
            symbol: fromSymbol
            anchors.verticalCenter: parent.verticalCenter
            onClicked: lookup.indicatorClicked()
        }
        SymbolButton {
            id: null_to
            symbol: "null-to"
            anchors.left: fromButton.right
            anchors.leftMargin: 3
            anchors.verticalCenter: parent.verticalCenter
        }
        SymbolButton {
            id: toButton
            symbol: toSymbol
            anchors.left: null_to.right
            anchors.leftMargin: 3
            anchors.verticalCenter: parent.verticalCenter
            onClicked: lookup.indicatorClicked()
        }
        RoundTextInput {
            id: queryText
            textColor: "black"
            height: parent.height
            anchors.left: toButton.right
            anchors.leftMargin: 3
            anchors.right: queryButton.left
            anchors.rightMargin: 3
            anchors.verticalCenter: parent.verticalCenter
            onTextChanged: query()
        }
        SymbolButton {
            id: queryButton
            symbol: "circle-go"
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
            onClicked: query()
        }
    }

    Rectangle {
        id: topHr
        height: 1
        anchors.top: navbar.bottom
        anchors.topMargin: 2
        color: "white"
    }

    InfiniteFlickable {
        id: yflick

        anchors.left: parent.left
        anchors.top: topHr.bottom
        anchors.right: parent.right
        anchors.bottom: parent.bottom

        contentWidth: parent.width * 1.5
        // alignColumn: false

        rows: 3
        columns: 1
        origRow: 1
        origColumn: 0

        onScrollUp: {
            var index = lookup.index - pageSize;
            if (index < 0)
                index = 0;
            scroll(index);
        }
        onScrollDown: {
            var index = lookup.index + pageSize;
            if (index >= dict.size - pageSize)
                index = dict.size - pageSize;
            if (index < 0)
                index = 0;
            scroll(index);
        }

        EntryContent {
            id: prev
            width: yflick.width * 2
            height: yflick.height
            font.pixelSize: fontSize
        }
        EntryContent {
            id: center
            width: yflick.width * 2
            height: yflick.height
            anchors.top: prev.bottom
            font.pixelSize: fontSize
        }
        EntryContent {
            id: next
            width: yflick.width * 2
            height: yflick.height
            anchors.top: center.bottom
            font.pixelSize: fontSize
        }
    }

    Row {
        id: footbar
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        spacing: 5

        SymbolButton {
            id: closeButton
            symbol: "circle-x"
            onClicked: lookup.closed()
        }
    }

    function query() {
        var index = dict.indexOf(queryText.text);
        if (index < 0)
            index = -index - 1;
        scroll(index);
    }

    function scroll(index) {
        lookup.index = index;
        load(prev, index - pageSize, index);
        load(center, index, index + pageSize);
        load(next, index + pageSize, index + pageSize * 2);
        yflick.home();
    }

    function load(ec, from, to) {
        if (from < 0) from = 0;
        if (to >= dict.size) to = dict.size;

        var s = "";
        for (var i = from; i < to; i++) {
            var word = dict.words[i];
            var entryText = word.name + ": " + word.description;
            s += entryText + "\n";
        }
        ec.text = s;
    }
}
