import QtQuick 1.1
import "../shared"

Scene {
    property string level: "未知"
    property int levelSize: 1
    property int testPassed: 1
    property int testSize: 1
    property int myTotal: 1

    property real vspacing: height * 0.05

    signal retry
    signal goBack

    id: scoreboard
    title: "分数"

    Text {
        id: congrats
        text: "恭喜您记住了"
        font.pixelSize: Math.min(parent.width, parent.height) / 10
        y: parent.height * 0.25
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Text {
        id: number
        text: testPassed
        font.pixelSize: congrats.font.pixelSize * 1.5
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: congrats.top
        anchors.topMargin: number.height + vspacing
    }

    Text {
        text: "个单词！"
        font.pixelSize: congrats.font.pixelSize
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: number.top
        anchors.topMargin: number.height + vspacing
    }

    Item {
        id: details
        visible: false
        clip: true

        ScoreText {
            id: levelLabel
            text: "词典："
            container: scoreboard
            x: parent.width * 0.2
            y: parent.height * 0.25
        }
        ScoreText {
            id: levelValue
            text: scoreboard.level
            container: scoreboard
            anchors.left: levelLabel.left
            anchors.leftMargin: scoreboard.width * 0.2
            anchors.top: levelLabel.bottom
            anchors.topMargin: vspacing
        }
        ScoreText {
            id: levelSizeLabel
            text: "词典条目数："
            container: scoreboard
            anchors.left: levelLabel.left
            anchors.top: levelValue.bottom
            anchors.topMargin: vspacing
        }
        ScoreText {
            id: levelSizeValue
            text: scoreboard.levelSize
            container: scoreboard
            anchors.left: levelLabel.left
            anchors.leftMargin: scoreboard.width * 0.2
            anchors.top: levelSizeLabel.bottom
            anchors.topMargin: vspacing
        }
        ScoreText {
            id: testLabel
            text: "本次增加的词汇量："
            container: scoreboard
            anchors.left: levelLabel.left
            anchors.top: levelSizeValue.bottom
            anchors.topMargin: vspacing
        }
        ScoreText {
            id: testValue
            text: scoreboard.testPassed + "/" + scoreboard.testCount
            container: scoreboard
            anchors.left: levelLabel.left
            anchors.leftMargin: scoreboard.width * 0.2
            anchors.top: testLabel.bottom
            anchors.topMargin: vspacing
        }
        ScoreText {
            id: myTotalLabel
            text: "我的总词汇量："
            container: scoreboard
            anchors.left: levelLabel.left
            anchors.top: testValue.bottom
            anchors.topMargin: vspacing
        }
        ScoreText {
            id: myTotalValue
            text: scoreboard.myTotal
            container: scoreboard
            anchors.left: levelLabel.left
            anchors.leftMargin: scoreboard.width * 0.2
            anchors.top: myTotalLabel.bottom
            anchors.topMargin: vspacing
        }
    }

    Row {
        id: buttons
        spacing: 30
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: parent.height * 0.1

        CoolButtonAuto {
            id: retry
            text: "重来"
            container: scoreboard
            onClicked: scoreboard.retry()
        }

        CoolButtonAuto {
            id: goBack
            text: "返回"
            container: scoreboard
            onClicked: scoreboard.goBack()
        }
    }

}
