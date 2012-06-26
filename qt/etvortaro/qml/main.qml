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

    Flickable {
        id: switcher
        x: 0
        y: 0
        width: parent.width
        height: parent.height
        contentWidth: width * 2
        contentHeight: height

        LookupEt {
            id: lookupEt
            width: switcher.width
            height:switcher.height
            onJumpToZh: switcher.state = 'zh'
        }

        LookupZh {
            id: lookupZh
            width: switcher.width
            height: switcher.height
            anchors.left: lookupEt.right
            anchors.leftMargin: 0
            onJumpToEt: switcher.state = 'et'
        }

        state: "et"
        states: [
            State {
                name: "et"
                PropertyChanges {
                    target: switcher
                    contentX: 0
                }
            },
            State {
                name: "zh"
                PropertyChanges {
                    target: switcher
                    contentX: switcher.width
                }
            }
        ]

        Behavior on contentX {
            NumberAnimation {
                target: switcher
                properties: "contentX"
                duration: 1000
                easing.type: Easing.InOutExpo
            }
        }

    }

    SequentialAnimation {
        id: fadeOutWelcome
        running: true
        PauseAnimation { duration: 3000 }
        NumberAnimation {
            target: welcome
            properties: "opacity"
            to: 0
            duration: 1000
        }
    }
}
