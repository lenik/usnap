// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import "../shared"

Rectangle {

    property alias ans1: ans1Button.text
    property alias ans2: ans2Button.text
    property alias ans3: ans3Button.text
    property string value

    property color shadeColor
    property string green
    property string red

    property real hmargin: parent.width * 0.025
    property real vmargin: parent.height * 0.10
    property real hspacing: parent.width * 0.10
    property real vspacing: parent.height * 0.05
    property real hspan: (width - hmargin * 2 - hspacing * 2)
    property real vspan: (height - vmargin * 2 - vspacing * 2) / 3 + vspacing

    signal choiced

    id: answer
    width: parent.width
    height: parent.height

    gradient: Gradient {
        GradientStop {
            position: 0
            color: "#cc666666"
        }
        GradientStop {
            position: 1
            color: "#cc777777"
        }
    }

    Rectangle {
        id: topBorder
        width: parent.width
        height: Math.min(vmargin, parent.height * 0.02)
        color: "white"
    }

    Rectangle {
        id: bottomBorder
        width: parent.width
        height: Math.min(vmargin, parent.height * 0.02)
        y: parent.height - height
        color: "white"
    }

    CoolButton {
        id: ans1Button
        x: hmargin + hspacing * 0
        y: vmargin + vspan * 0
        width: hspan
        height: vspan - vspacing
        // text: "Answer 1"
        shadeColor: text == red ? "red" : text == green ? "green" : answer.shadeColor
        onClicked: { answer.value = text; answer.choiced() }
    }

    CoolButton {
        id: ans2Button
        x: hmargin + hspacing * 1
        y: vmargin + vspan * 1
        width: hspan
        height: vspan - vspacing
        // text: "Answer 2"
        shadeColor: text == red ? "red" : text == green ? "green" : answer.shadeColor
        onClicked: { answer.value = text; answer.choiced() }
    }

    CoolButton {
        id: ans3Button
        x: hmargin + hspacing * 2
        y: vmargin + vspan * 2
        width: hspan
        height: vspan - vspacing
        // text: "Answer 3"
        shadeColor: text == red ? "red" : text == green ? "green" : answer.shadeColor
        onClicked: { answer.value = text; answer.choiced() }
    }

}
