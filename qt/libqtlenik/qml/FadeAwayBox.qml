import QtQuick 1.0

Rectangle {
    property real speed: 5
    property bool fadeIn: true
    property bool fadeOut: true
    signal appeared
    signal disappeared

    id: box
    // clip: true

    states: [
        State {
            name: "coming"
            PropertyChanges {
                target: box
                opacity: 0
            }
        },
        State {
            name: "away"
            PropertyChanges {
                target: box
                opacity: 0
            }
        }
    ]

    transitions: [
        Transition {
            from: "coming"
            SequentialAnimation {
                NumberAnimation {
                    target: box
                    property: "opacity"
                    duration: fadeIn ? (5000 / box.speed) : 10
                    easing.type: Easing.OutCubic
                }
                ScriptAction { script: box.appeared() }
            }
        },
        Transition {
            to: "away"
            SequentialAnimation {
                NumberAnimation {
                    target: box
                    property: "opacity"
                    duration: fadeOut ? (5000 / box.speed) : 10
                    easing.type: Easing.OutCubic
                }
                ScriptAction { script: box.disappeared() }
            }
        }
    ]

}
