import QtQuick 1.0

Flipable {
    property int speed: 10

    id: flipable

    transform: Rotation {
        id: rotation
        origin.x: flipable.width/2
        origin.y: flipable.height/2
        axis.x: 1; axis.y: 0; axis.z: 0
    }

    states: State {
        name: "back"
        when: flipable.flipped
        PropertyChanges { target: rotation; angle: 180 }
    }

    transitions: Transition {
        NumberAnimation {
            target: rotation
            property: "angle"
            duration: 5000 / speed
            // easing.type: Easing.InOutQuad
        }
    }
}
