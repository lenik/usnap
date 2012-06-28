// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import "../shared"

Item {
    id: item

    property alias text: button.text
    signal clicked

    width: button.textWidth + 30
    height: button.textHeight + 10

    CoolButton {
        id: button
        style: "gray"
        font.pixelSize:Math.min(item.parent.width, item.parent.height) / 15
        anchors.fill: parent
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
