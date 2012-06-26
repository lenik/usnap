import QtQuick 1.1
import "../shared"

Scene {
    signal jumpToZh

    id: lookupEt

    Item {
        id: navbar
        height: circ_et.height
        SymbolButton {
            id: circ_et
            symbol: "circle-et"
            onClicked: lookupEt.jumpToZh()
            anchors.verticalCenter: parent.verticalCenter
        }
        SymbolButton {
            id: null_to
            symbol: "null-to"
            anchors.left: circ_et.right
            anchors.leftMargin: 3
            anchors.verticalCenter: parent.verticalCenter
        }
        SymbolButton {
            id: circ_zh
            symbol: "circle-zh"
            onClicked: lookupEt.jumpToZh()
            anchors.left: null_to.right
            anchors.leftMargin: 3
            anchors.verticalCenter: parent.verticalCenter
        }
        TextInput {
            id: queryText
            anchors.left: circ_zh.right
            anchors.leftMargin: 3
            anchors.right: circ_go.left
            anchors.rightMargin: 3
            anchors.verticalCenter: parent.verticalCenter
        }
        SymbolButton {
            id: circ_go
            symbol: "circle-go"
            onClicked: lookup()
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
        id: content

        anchors.left: parent.left
        anchors.top: topHr.bottom
        anchors.right: parent.right
        anchors.bottom: parent.bottom

        rows: 3
        columns: 1
        origRow: 1
        origColumn: 0

        Rectangle {
            id: top
            width: content.width
            height: content.height
            color: "gray"
            opacity: 0.2
        }
        Rectangle {
            id: mid
            width: content.width
            height: content.height
            color: "gray"
            opacity: 0.2
            anchors.top: top.bottom
        }
        Rectangle {
            id: bottom
            width: content.width
            height: content.height
            color: "gray"
            opacity: 0.2
            anchors.top: mid.bottom
        }
    }

}
