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

    property real scaleX: width / 320
    property real scaleY: height / 640

    function show() {
        slideIn.start();
    }

    topStyle: "sky2"
    bottomStyle: "mountain"
    border {
        left: 176 * scaleRatio; top: 190 * scaleRatio
        right: 250 * scaleRatio; bottom: 0 * scaleRatio }

    title: "选择难度等级"

    BookIcon {
        id: eo1
        x: 19 * scaleX
        y: 272 * scaleY
        text: "世界语 1"
        onClicked: chooser.chosen("eo-1")
    }
    BookIcon {
        id: eo2
        x: 55 * scaleX
        y: 366 * scaleY
        text: "世界语 2"
        onClicked: chooser.chosen("eo-2")
    }
    BookIcon {
        id: eo3
        x: 55 * scaleX
        y: 459 * scaleY
        text: "世界语 3"
        onClicked: chooser.chosen("eo-3")
    }
    BookIcon {
        id: eo4
        x: 19 * scaleX
        y: 539 * scaleY
        text: "世界语 4"
        onClicked: chooser.chosen("eo-4")
    }
    BookIcon {
        id: en1
        x: 211 * scaleX
        y: 230 * scaleY
        text: "英语 2"
        onClicked: chooser.chosen("en-1")
    }
    BookIcon {
        id: en2
        x: 184 * scaleX
        y: 321 * scaleY
        text: "英语 3"
        onClicked: chooser.chosen("en-2")
    }
    BookIcon {
        id: en3
        x: 154 * scaleX
        y: 413 * scaleY
        text: "英语 4"
        onClicked: chooser.chosen("en-3")
    }
    BookIcon {
        id: en4
        x: 184 * scaleX
        y: 496 * scaleY
        text: "英语 6"
        onClicked: chooser.chosen("en-4")
    }
    BookIcon {
        id: en5
        x: 211 * scaleX
        y: 578 * scaleY
        text: "英语 8"
        onClicked: chooser.chosen("en-5")
    }

    SequentialAnimation {
        id: slideIn
        ScriptAction { script: eo1.state = "" }
        PauseAnimation { duration: 1000 / slideSpeed }
        ScriptAction { script: eo2.state = "" }
        PauseAnimation { duration: 1000 / slideSpeed }
        ScriptAction { script: eo3.state = "" }
        PauseAnimation { duration: 1000 / slideSpeed }
        ScriptAction { script: eo4.state = "" }
        PauseAnimation { duration: 1000 / slideSpeed }
        ScriptAction { script: en1.state = "" }
        PauseAnimation { duration: 1000 / slideSpeed }
        ScriptAction { script: en2.state = "" }
        PauseAnimation { duration: 1000 / slideSpeed }
        ScriptAction { script: en3.state = "" }
        PauseAnimation { duration: 1000 / slideSpeed }
        ScriptAction { script: en4.state = "" }
        PauseAnimation { duration: 1000 / slideSpeed }
        ScriptAction { script: en5.state = "" }
    }
}
