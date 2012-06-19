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

    CoolButton {
        id: level1
        x: -200
        y: 145
        width: 190
        height: 35
        text: "Level 1"
        anchors.bottom: level2.top
        anchors.bottomMargin: vspacing
    }
    CoolButton {
        id: level2
        x: -200
        y: 180
        width: 190
        height: 35
        text: "Level 2"
        anchors.bottom: level3.top
        anchors.bottomMargin: vspacing
    }

    CoolButton {
        id: level3
        x: -200
        y: 215
        width: 190
        height: 35
        text: "Level 3"
        anchors.bottom: level4.top
        anchors.bottomMargin: vspacing
    }
    CoolButton {
        id: level4
        x: -200
        y: 242
        width: 190
        height: 35
        text: "Level 4"
        anchors.bottom: level5.top
        anchors.bottomMargin: vspacing
        anchors.horizontalCenterOffset: 0
        onClicked: chooser.select("level-4")
    }

    CoolButton {
        id: level5
        x: -200
        y: 285
        width: 190
        height: 35
        text: "Level 5"
        anchors.horizontalCenterOffset: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 30
    }

    ParallelAnimation {
        id: slideIn
        running: true
        SequentialAnimation {
            PauseAnimation { duration: 0 }
            NumberAnimation {
                target: level1; property: "x"; duration: 1000; easing.type: Easing.OutBounce
                to: (chooser.width - level1.width) / 2
            }
        }
        SequentialAnimation {
            PauseAnimation { duration: 1000 / slideSpeed }
            NumberAnimation {
                target: level2; property: "x"; duration: 1000; easing.type: Easing.OutBounce
                to: (chooser.width - level2.width) / 2
            }
        }
        SequentialAnimation {
            PauseAnimation { duration: 2000 / slideSpeed }
            NumberAnimation {
                target: level3; property: "x"; duration: 1000; easing.type: Easing.OutBounce
                to: (chooser.width - level3.width) / 2
            }
        }
        SequentialAnimation {
            PauseAnimation { duration: 3000 / slideSpeed }
            NumberAnimation {
                target: level4; property: "x"; duration: 1000; easing.type: Easing.OutBounce
                to: (chooser.width - level4.width) / 2
            }
        }
        SequentialAnimation {
            PauseAnimation { duration: 4000 / slideSpeed }
            NumberAnimation {
                target: level5; property: "x"; duration: 1000; easing.type: Easing.OutBounce
                to: (chooser.width - level5.width) / 2
            }
        }
    }

}
