// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import "../shared"

CoolButton {
    // property alias abc: text

    id: button
    font.pixelSize: (parent.width < parent.height ? parent.width : parent.height) / 20
    width: text.length * font.pixelSize
    height: parent.height / 20
    x: 50

    states: [
        State {
            name: "Visible"
            AnchorChanges {
                target: button
                anchors.horizontalCenter: parent.horizontalCenter
            }
        },
        State {
            name: "pressed"
            AnchorChanges {
                target: button
                anchors.horizontalCenter: parent.horizontalCenter
            }
        },
        State {
            name: "Loaded"
            AnchorChanges {
                target: button
                anchors.horizontalCenter: undefined
            }
            PropertyChanges {
                target: button
                x: 300
            }
        }

    ]

    transitions: [
        Transition {
            to: "Visible"
            AnchorAnimation {
                duration: 1000
                easing.type: Easing.OutBounce
            }
        },
        Transition {
            to: "pressed"
            AnchorAnimation {
                duration: 1000
                easing.type: Easing.OutBounce
            }
        },
        Transition {
            to: "Loaded"
            AnchorAnimation {
                duration: 500
                easing.type: Easing.InBounce
            }
        }
    ]

    onClicked: {
        button.state = "Loaded"
    }

    Timer {
        interval: 100
        running: true
        repeat: true
        onTriggered: button.text = button.state
    }

}
