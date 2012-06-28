import QtQuick 1.1
import "../shared"
import "Test.js" as TestEngine

Scene {
    property int speed: 10
    property variant table: [
            [ "猫", "cat", "/'kaet/", "tac", "dog" ],
            [ "狗", "dog", "/'dog/", "bird", "house" ],
            [ "骆驼", "camel", "/'kaemel/", "lamo", "what the fuck..." ],
        ]
    property int index: 0
    property bool backward: false
    property bool leftSide: true

    property alias promptFont: promptText.font

    signal scoreChanged
    signal end

    function start() {
        TestEngine.candidates = [];
        TestEngine.answers = [];
        showWord(index = 0);
    }

    function stop() {
        // timer.stop();
    }

    function showWord(index, backward) {
        var entry = table[index];
        var word = entry[1];
        var description = entry[0];
        var sound = entry[2];
        var candidates = [ word ];
        for (var i = 3; i < entry.length; i++) {
            candidates[(i - 3) + 1] = entry[i];
        }
        for (var shuffle = 0; shuffle < 10; shuffle++) {
            var p = Math.floor(Math.random() * candidates.length);
            var q = Math.floor(Math.random() * candidates.length);
            if (p != q) {
                var a = candidates[p];
                var b = candidates[q];
                candidates[p] = b;
                candidates[q] = a;
            }
        }
        TestEngine.candidates = candidates;

        promptText.text = description + "?";
        promptBox.state = "coming";
        promptBox.state = "";

        if (backward) {
            if (! leftSide) {
                leftSide = true;
            } else {
                cRight.ans1 = cLeft.ans1
                cRight.ans2 = cLeft.ans2
                cRight.ans3 = cLeft.ans3
            }
            cLeft.ans1 = candidates[0];
            cLeft.ans2 = candidates[1];
            cLeft.ans3 = candidates[2];
            flick1.state = "right";
            flick1.state = "";
        } else {
            if (leftSide) {
                leftSide = false;
            } else {
                cLeft.ans1 = cRight.ans1
                cLeft.ans2 = cRight.ans2
                cLeft.ans3 = cRight.ans3
            }
            cRight.ans1 = candidates[0];
            cRight.ans2 = candidates[1];
            cRight.ans3 = candidates[2];
            flick1.state = "";
            flick1.state = "right";
        }
    }

    function setAnswer(index, answer) {
        TestEngine.answers[index] = answer;
        test.scoreChanged();
    }

    function getScore() {
        var matchings = 0;
        for (var i = 0; i < table.length; i++) {
            var expected = table[i][1];
            var actual = TestEngine.answers[i];
            if (expected == actual)
                matchings++;
        }
        return matchings;
    }

    id: test
    title: "选择正确的单词"

    FadeAwayBox {
        id: promptBox
        width: parent.width
        height: promptText.height + 10
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: flick1.top
        anchors.bottomMargin: 15

        fadeOut: false

        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#33444444"
            }
            GradientStop {
                position: 1
                color: "#33222222"
            }
        }

        Text {
            id: promptText
            width: parent.width
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            text: "Hello, world"
            color: "black"
            font.family: "Comic Sans MS"
            font.pixelSize: parent.width / 12
            wrapMode: Text.WrapAnywhere
            horizontalAlignment: Text.AlignHCenter
        }

        state: ""
        // onAppeared: timer.start();
        onDisappeared: {
            if (index < table.length) {
                showWord(index, backward);
            } else {
                test.end();
            }
        }
    }

    Flickable {
        id: flick1
        x: 0
        y: parent.height * 0.4
        width: test.width
        height: parent.height * 0.35
        contentWidth: row.width
        contentHeight: height

        Row {
            id: row
            height: parent.height
            Choices {
                id: cLeft
                width: test.width
                height: parent.height
                shadeColor: "red"
                green: index < table.length ? table[index][1] : ""
                onChoiced: {
                    backward = false;
                    setAnswer(index, cLeft.value);
                    index++;
                    if (index < table.length)
                        promptBox.state = "away";
                    else
                        test.end();
                }
            }
            Choices {
                id: cRight
                width: test.width
                height: parent.height
                shadeColor: "red"
                green: index < table.length ? table[index][1] : ""
                onChoiced: {
                    backward = false;
                    setAnswer(index, cRight.value);
                    index++;
                    if (index < table.length)
                        promptBox.state = "away";
                    else
                        test.end();
                }
            }
        }

        states: [
            State {
                name: "right"
                PropertyChanges {
                    target: flick1
                    contentX: test.width
                }
            }
        ]

        transitions: [
            Transition {
                to: "right"
                NumberAnimation {
                    target: flick1
                    property: "contentX"
                    duration: 1000
                    easing.type: Easing.OutCubic
                }
            }
        ]
    }

    Row {
        id: buttons
        spacing: 30
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: parent.height * 0.1

        CoolButtonAuto {
            id: backwardButton
            visible: index > 0
            text: "退回"
            container: test
            onClicked: {
                backward = true;
                index--;
                promptBox.state = "away";
            }
        }

        CoolButtonAuto {
            id: seeScore
            text: "查看得分"
            container: test
            onClicked: { test.stop(); test.end(); }
        }
    }

}
