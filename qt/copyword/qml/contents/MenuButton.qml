// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import "../shared"

Item {
    id: item

    property alias text: button.text
    signal clicked

    width: button.textWidth + 30
    height: button.textHeight + 10
    x: -width

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

    states: [
        State {
            name: "stand"
            AnchorChanges {
                target: item
                anchors.horizontalCenter: parent.horizontalCenter
            }
        },
        State {
            name: "away"
            AnchorChanges {
                target: item
                anchors.horizontalCenter: undefined
            }
            PropertyChanges {
                target: item
                x: parent.width
            }
        }

    ]

    transitions: [
        Transition {
            to: "stand"
            AnchorAnimation {
                duration: 1000
                easing.type: Easing.OutBounce
            }
        },
        Transition {
            to: "away"
            AnchorAnimation {
                duration: 500
                easing.type: Easing.InBounce
            }
        }
    ]

}
