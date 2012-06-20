// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import "../shared"

Rectangle {
    id: chooser

    property int vspacing: 5
    property string book
    property int slideSpeed: 10

    signal select(string book)

    gradient: Gradient {
        GradientStop {
            position: 0
            color: "#ffffff"
        }

        GradientStop {
            position: 1
            color: "#ff9500"
        }
    }

    Text {
        id: prompt
        color: "#ff0000"
        text: "Choose eng book"
        anchors.left: parent.left
        anchors.leftMargin: 30
        anchors.top: parent.top
        anchors.topMargin: 10
        font.family: "Comic Sans MS"
        font.pixelSize: 32
    }

    MenuButton {
        id: level1
        x: -200
        y: 145
        height: 35
        text: "Basic"
        anchors.bottom: level2.top
        anchors.bottomMargin: vspacing
    }
    MenuButton {
        id: level2
        x: -200
        y: 180
        height: 35
        text: "Medium I"
        anchors.bottom: level3.top
        anchors.bottomMargin: vspacing
    }
    MenuButton {
        id: level3
        x: -200
        y: 215
        height: 35
        text: "Medium II"
        anchors.bottom: level4.top
        anchors.bottomMargin: vspacing
    }
    MenuButton {
        id: level4
        x: -200
        y: 242
        height: 35
        text: "Crazy"
        anchors.bottom: level5.top
        anchors.bottomMargin: vspacing
        onClicked: chooser.select("level-4")
    }
    MenuButton {
        id: level5
        x: -200
        y: 285
        height: 35
        text: "Mad"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 30
    }

    SequentialAnimation {
        id: slideIn
        running: true
        ScriptAction { script: level1.state = "Visible" }
        PauseAnimation { duration: 1000 / slideSpeed }
        ScriptAction { script: level2.state = "Visible" }
        PauseAnimation { duration: 1000 / slideSpeed }
        ScriptAction { script: level3.state = "Visible" }
        PauseAnimation { duration: 1000 / slideSpeed }
        ScriptAction { script: level4.state = "Visible" }
        PauseAnimation { duration: 1000 / slideSpeed }
        ScriptAction { script: level5.state = "Visible" }
    }

}
