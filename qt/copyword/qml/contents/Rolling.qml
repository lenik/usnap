import QtQuick 1.1
import "../shared"

Scene {
    property int speed: 10
    property variant table: [
            [ "猫", "cat", "tac", "dog" ],
            [ "狗", "dog", "bird", "house" ],
            [ "骆驼", "camel", "lamo", "what the fuck..." ]
        ]
    property int index: 0

    signal end

    id: rolling
    title: "单词滚动记忆中……"

    width: 300
    height: 400

    FlyAwayBox {
        id: fly1
        y0: parent.height * 0.3
        width: parent.width * 0.75
        height: parent.height * 0.4
        radius: 10
        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#808080"
            }
            GradientStop {
                position: 1
                color: "#40404020"
            }
        }
        anchors.horizontalCenter: parent.horizontalCenter

        Text {
            id: flyText1
            anchors.fill: parent
            anchors.margins: font.pixelSize
            color: "white"
        }

        state: "coming"
        onAppeared: {
            var entry = table[index++];
            var word = entry[1];
            var description = entry[0];
            flyText1.text = "ENTRY" + word + ": \n" + description;
            console.log("on-appear");
            timer.start();
        }
        onDisappeared: {
            if (index < table.length) {
                fly1.state = "coming"
                fly1.state = ""
            }
        }
    }

    Timer {
        id: timer
        interval: 5000 / speed
        repeat: false
        onTriggered: fly1.state = "away"
    }

    // TODO slider bar for speed adjustment.

    Row {
        id: buttons
        spacing: 30
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: parent.height * 0.1

        CoolButtonAuto {
            id: seeScore
            text: "查看得分"
            container: rolling
            onClicked: rolling.end()
        }

        CoolButtonAuto {
            id: stateHelper
            container: rolling
        }
    }

    Timer {
        running: true
        repeat: true
        interval: 100
        onTriggered: stateHelper.text = "["+index+"]" + fly1.state
    }

    ScriptAction {
        running: true
        script: {
            fly1.state = ""
            console.log("script")
        }
    }
}
