import QtQuick 1.1
import "shared"
import "contents"

Rectangle {
    property bool debug: false
    property int pageSize: 18

    id: screen

    width: debug ? 240 : 480
    height: debug ? 400 : 854
    color: "lightgray"

    Welcome {
        id: welcome
        anchors.fill: parent
        opacity: 1
        z: 10
        onBegan: welcome.opacity = 0
        onInfoClicked: about.opacity = 1
        // ScriptAction { running: true; script: load() }
    }

    About {
        id: about
        width: parent.width * 0.8
        height: parent.height * 0.25
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        opacity: 0
        z: 11
        onClosed: about.opacity = 0

        Behavior on opacity {
            NumberAnimation {
                target: about
                properties: "opacity"
                duration: 750
                easing.type: Easing.Linear
            }
        }
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
            // pageSize: screen.pageSize
            dict: etDict
            fromSymbol: "circle-et"
            toSymbol: "circle-zh"
            onIndicatorClicked: {
                switcher.state = 'back';
                lookupZh.text = lookupEt.text;
                lookupZh.query();
            }
            onClosed: Qt.quit()
        }

        back: Lookup {
            id: lookupZh
            width: switcher.width
            height: switcher.height
            // pageSize: screen.pageSize
            dict: zhDict
            fromSymbol: "circle-zh"
            toSymbol: "circle-et"
            onIndicatorClicked: {
                switcher.state = 'front';
                lookupEt.text = lookupZh.text;
                lookupEt.query();
            }
            onClosed: Qt.quit()
        }
    }

    SequentialAnimation {
        id: fadeOutWelcome
        running: false
        PauseAnimation { duration: 1000 }
        NumberAnimation {
            target: welcome
            properties: "opacity"
            to: 0
            duration: 1000
        }
    }
}
