import QtQuick 1.1
import "../shared"

Scene {
    id: rolling
    title: "选择正确的单词"

    property alias title: titleText.text
    property alias color: titleText.color

    gradient: Gradient {
        GradientStop {
            position: 0
            color: "#7a7a7a"
        }
        GradientStop {
            position: 0.2
            color: "#ffffff"
        }
        GradientStop {
            position: 1
            color: "#424242"
        }
    }

    Text {
        id: titleText
        color: "#521fd5"
        anchors.left: parent.left
        anchors.leftMargin: 40
        anchors.top: parent.top
        anchors.topMargin: 20
        font.family: "Comic Sans MS"
        font.pixelSize: 32
    }

}
