import QtQuick 1.1
import "../shared"

Item {
    property alias source: image.source
    property alias overlay: overlayRect

    signal fadeAway

    id: popup
    // clip: true
    state: "below"

    anchors.left: parent.left
    anchors.right: parent.right

    Rectangle {
        id: overlayRect
        color: "black"
        opacity: 0.3
        anchors.fill: parent
    }

    Image {
        id: image
        width: parent.width
        height: parent.height * 0.8
        fillMode: Image.PreserveAspectFit
        anchors.centerIn: parent
        z: 1
    }

    states: [
        State {
            name: "below"
            PropertyChanges {
                target: popup
                y: popup.parent.height
            }
        },
        State {
            name: "fadeOut"
            PropertyChanges {
                target: popup
                opacity: 0
            }
        }
    ]

    transitions: [
        Transition {
            from: "below"
            SequentialAnimation {
                PropertyAnimation {
                    target: popup
                    properties: "y"
                    duration: 1000
                    easing.type: Easing.OutExpo
                }
                ScriptAction {
                    script: popup.fadeAway();
                }
            }
        },
        Transition {
            to: "fadeOut"
            SequentialAnimation {
                PropertyAnimation {
                    target: popup
                    properties: "opacity"
                    duration: 1000
                }
                ScriptAction {
                    // script: popup.fadeAway()
                }
            }
        }
    ]
}
