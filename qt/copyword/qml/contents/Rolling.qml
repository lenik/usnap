import QtQuick 1.1
import "../shared"

Scene {
    property real speed: 1
    property variant table: [
            [ "猫", "cat", "/'kaet/", "tac", "dog" ],
            [ "狗", "dog", "/'dog/", "bird", "house" ],
            [ "骆驼", "camel", "/'kaemel/", "lamo", "what the fuck..." ]
        ]
    property int index: 0
    // property alias flyFont: description.font

    signal done
    signal skipped

    function start() {
        showWord(index = 0);
    }

    function stop() {
        // timer.running = false
    }

    function showWord(index) {
        var entry = table[index];
        var description = entry[0];
        var word = entry[1];
        var sound = entry[2];
        wordText.text = /*"(" + index + ") " +*/ word;
        descriptionText.text = description;
        soundText.text = sound;
        fly1.state = "coming";
        fly1.state = "";
    }

    id: rolling
    title: "单词滚动记忆"

    FlyAwayBox {
        id: fly1
        radius: 10
        y0: parent.height * 0.2
        width: parent.width * 0.75
        height: parent.height * 0.55
        anchors.horizontalCenter: parent.horizontalCenter
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

        Text {
            id: wordText
            anchors.top: parent.top
            anchors.topMargin: font.pixelSize * 0.75
            anchors.left: parent.left
            anchors.leftMargin: font.pixelSize * 0.75
            color: "white"
            font.family: "Comic Sans MS"
            font.pixelSize: parent.width / 8
            wrapMode: Text.NoWrap
        }

        Text {
            id: soundText
            anchors.top: wordText.bottom
            anchors.topMargin: 0
            anchors.right: parent.right
            anchors.rightMargin: font.pixelSize
            color: "lightblue"
            font.family: "Sans Serif"
            font.pixelSize: parent.width / 10
            wrapMode: Text.NoWrap
        }

        Text {
            id: descriptionText
            anchors.top: soundText.bottom
            anchors.topMargin: 3
            anchors.left: parent.left
            anchors.leftMargin: font.pixelSize * 0.8
            anchors.right: parent.right
            anchors.rightMargin: font.pixelSize * 0.8
            anchors.bottom: parent.bottom
            color: "white"
            font.family: "Comic Sans MS"
            font.pixelSize: parent.width / 11
            wrapMode: Text.Wrap
        }

        state: "coming"
        onAppeared: timer.start();
        onDisappeared: (++index < table.length) ? showWord(index) : rolling.done()
    }

    Timer {
        id: timer
        interval: 1000 / speed
        repeat: false
        running: pauseButton.state != "pressed"
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
            id: pauseButton
            text: state == "pressed" ? "继续" : "暂停"
            container: rolling
            shadeColor: "red"
        }

        CoolButtonAuto {
            id: skip
            text: "跳过"
            container: rolling
            onClicked: { rolling.stop(); rolling.skipped(); }
        }
    }

}
