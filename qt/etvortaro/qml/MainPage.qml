import QtQuick 1.1
import com.nokia.meego 1.0
import "shared"
import "contents"

Page {
    id: mainPage
    tools: systemTools

    Welcome {
        id: welcome
        anchors.fill: parent
        opacity: 1
        z: 10
        onBegan: welcome.opacity = 0
        // ScriptAction { running: true; script: load() }
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
            // pageSize: toplevel.pageSize
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
            // pageSize: toplevel.pageSize
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
