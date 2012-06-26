import QtQuick 1.1
import "../shared"

Scene {
    property string fromSymbol
    property string toSymbol
    property variant dict

    signal indicatorClicked

    id: lookup

    Item {
        id: navbar
        width: parent.width
        height: fromButton.height
        SymbolButton {
            id: fromButton
            symbol: fromSymbol
            onClicked: lookup.indicatorClicked()
            anchors.verticalCenter: parent.verticalCenter
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
            onClicked: lookup.indicatorClicked()
            anchors.left: null_to.right
            anchors.leftMargin: 3
            anchors.verticalCenter: parent.verticalCenter
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
            onTextChanged: query();
        }
        SymbolButton {
            id: queryButton
            symbol: "circle-go"
            onClicked: query()
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
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

        rows: 3
        columns: 1
        origRow: 1
        origColumn: 0

        EntryContent {
            id: prev
            width: yflick.width
            height: yflick.height
        }
        EntryContent {
            id: center
            width: yflick.width
            height: yflick.height
            anchors.top: prev.bottom
        }
        EntryContent {
            id: next
            width: yflick.width
            height: yflick.height
            anchors.top: center.bottom
        }
    }

    function query() {
        var index = dict.indexOf(queryText.text);
        if (index < 0)
            index = -index - 1;
        scroll(index);
    }

    function scroll(index) {
        load(prev, index - 5, index);
        load(center, index, index + 5);
        load(next, index + 5, index + 10);
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
