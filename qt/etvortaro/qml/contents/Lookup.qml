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
            anchors.right: parent.right
            anchors.rightMargin: 3
            anchors.verticalCenter: parent.verticalCenter
            onTextChanged: query()
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

    function query() {
        var index = dict.indexOf(queryText.text);
        var hint;
        if (index < 0) {
            index = -index - 1;
            if (queryText.text == "")
                hint = "（请输入要查找的单词。）\n";
            else
                hint = "（未找到单词 " + queryText.text + "。）\n";
        }
        scroll(index, hint);
    }

    function scroll(index, hint) {
        lookup.index = index;
        load(prev, index - pageSize, index);

        var offset = index;
        var size1 = pageSize;
        // if (hint !== null) size1--;
        load(center, offset, offset + size1, hint);
        offset += size1;

        load(next, offset, offset + pageSize);
        yflick.home();
    }

    function load(ec, from, to, hint) {
        if (from < 0) from = 0;
        if (to >= dict.size) to = dict.size;

        var s = hint === undefined ? "" : hint;
        for (var i = from; i < to; i++) {
            var word = dict.words[i];
            var entryText = word.name + ": " + word.description;
            s += entryText + "\n";
        }
        ec.text = s;
    }

}
