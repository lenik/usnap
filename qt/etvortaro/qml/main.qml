import QtQuick 1.1
import "shared"
import "contents"

Rectangle {
    id: screen

    width: 240
    height: 400
    color: "lightgray"

    Welcome {
        id: welcome
        anchors.fill: parent
        opacity: 100
        z: 100
        onBegan: welcome.opacity = 0
    }

    YFlipable {
        id: switcher
        x: 0
        y: 0
        width: parent.width
        height: parent.height

        front: Lookup {
            id: lookupEt
            width: switcher.width
            height:switcher.height
            dict: etDict
            fromSymbol: "circle-zh"
            toSymbol: "circle-et"
            onIndicatorClicked: switcher.state = 'back'
        }

        back: Lookup {
            id: lookupZh
            width: switcher.width
            height: switcher.height
            dict: zhDict
            fromSymbol: "circle-zh"
            toSymbol: "circle-et"
            onIndicatorClicked: switcher.state = 'front'
        }
    }

    SequentialAnimation {
        id: fadeOutWelcome
        running: true
        PauseAnimation { duration: 1000 }
        NumberAnimation {
            target: welcome
            properties: "opacity"
            to: 0
            duration: 1000
        }
    }
}
