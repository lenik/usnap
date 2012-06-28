// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import "../shared"
import "Chooser.js" as ChooserEngine

Scene {
    id: chooser

    property int vspacing: 5
    property string book
    property int slideSpeed: 10

    signal chosen(string bookName)

    function show() {
        level1.state = "";
        level2.state = "";
        level3.state = "";
        level4.state = "";
        level5.state = "";
        slideIn.start();
    }

    topStyle: "sky2"
    bottomStyle: "mountain"
    border {
        left: 176 * scaleRatio; top: 190 * scaleRatio
        right: 250 * scaleRatio; bottom: 0 * scaleRatio }

    title: "选择难度等级"

    MenuButton {
        id: level1
        text: "Basic / 简单"
        anchors.bottom: level2.top
        anchors.bottomMargin: vspacing
        onClicked: chooser.chosen("level-1")
    }
    MenuButton {
        id: level2
        text: "Medium / 普通"
        anchors.bottom: level3.top
        anchors.bottomMargin: vspacing
        onClicked: chooser.chosen("level-2")
    }
    MenuButton {
        id: level3
        text: "High / 提高"
        anchors.bottom: level4.top
        anchors.bottomMargin: vspacing
        onClicked: chooser.chosen("level-3")
    }
    MenuButton {
        id: level4
        text: "Crazy / 超难"
        anchors.bottom: level5.top
        anchors.bottomMargin: vspacing
        onClicked: chooser.chosen("level-4")
    }
    MenuButton {
        id: level5
        text: "Mad / 疯狂"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 30
        onClicked: chooser.chosen("level-5")
    }

    SequentialAnimation {
        id: slideIn
        ScriptAction { script: level1.state = "stand" }
        PauseAnimation { duration: 1000 / slideSpeed }
        ScriptAction { script: level2.state = "stand" }
        PauseAnimation { duration: 1000 / slideSpeed }
        ScriptAction { script: level3.state = "stand" }
        PauseAnimation { duration: 1000 / slideSpeed }
        ScriptAction { script: level4.state = "stand" }
        PauseAnimation { duration: 1000 / slideSpeed }
        ScriptAction { script: level5.state = "stand" }
    }

}
