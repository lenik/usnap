import QtQuick 1.0

BorderImage {
    id: button

    property alias text: buttonText.text
    property alias font: buttonText.font
    property alias textWidth: buttonText.width
    property alias textHeight: buttonText.height
    property alias shadeColor: shade.color

    property string style: "gray"

    signal clicked

    source: "images/button-" + style + ".png"; clip: true
    border { left: 10; top: 10; right: 10; bottom: 10 }

    Rectangle {
        id: shade
        anchors.fill: button; radius: 10; color: "black"; opacity: 0
    }

    Text {
        id: buttonText
        anchors.centerIn: parent; anchors.verticalCenterOffset: -1
        font.pixelSize: Math.min(parent.width, parent.height) * .5
        style: Text.Sunken; color: "white"; styleColor: "black"; smooth: true
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: button.clicked()
    }

    states: State {
        name: "pressed"; when: mouseArea.pressed == true
        PropertyChanges { target: shade; opacity: .4 }
    }
}
