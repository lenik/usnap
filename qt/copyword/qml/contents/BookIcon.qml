// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import "../shared"

Item {
    id: item

    property alias text: itemText.text
    signal clicked

    width: itemText.width + 30
    height: itemText.height + 10

    SymbolButton {
        id: button
        symbol: "cloud"
        anchors.fill: parent

        Text {
            id: itemText
            anchors.centerIn: parent
            font.pixelSize:Math.min(item.parent.width, item.parent.height) / 15
            color: "black"
            style: Text.Raised
            styleColor: "gray"
        }

        onClicked: {
            item.state = "away"
            item.clicked()
        }
    }

    Behavior on x {
        NumberAnimation {
            target: item
            property: "x"
            duration: 1000
            easing.type: Easing.OutBounce
        }
    }

    state: "far"

    states: [
        State {
            name: "far"
            PropertyChanges {
                target: item
                x: -item.width
            }
        },
        State {
            name: "away"
            PropertyChanges {
                target: item
                x: parent.width
            }
        }

    ]

    transitions: [
        Transition {
            from: "far"
            PropertyAnimation {
                duration: 1000
                easing.type: Easing.OutBounce
            }
        },
        Transition {
            to: "away"
            PropertyAnimation {
                duration: 1000
                easing.type: Easing.OutBounce
            }
        }
    ]

}
