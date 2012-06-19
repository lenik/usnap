// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import "shared"

Rectangle {
    id: chooseBook
    width: 360
    height: 360
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
        id: text1
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
        id: coolbutton1
        x: 74
        y: 101
        width: 165
        height: 113
        label: "Level 1"
        style: "gray"
    }


}
