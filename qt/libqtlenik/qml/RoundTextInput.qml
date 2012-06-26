import QtQuick 1.0

BorderImage {
    property string borderColor: "white"
    property real borderRadius: 10
    property real borderCut: borderRadius + 1
    property alias shader: shaderRectangle
    property alias text: input.text
    property alias textWidth: input.width
    property alias textHeight: input.height
    property alias textColor: input.color
    property alias font: input.font

    signal textChanged

    id: control
    source: "images/rc-" + borderColor + "-" + borderRadius + ".png"
    border { left: borderCut; top: borderCut; right: borderCut; bottom: borderCut }
    horizontalTileMode: BorderImage.Stretch
    verticalTileMode: BorderImage.Repeat

    clip: true

    Rectangle {
        id: shaderRectangle
        anchors.fill: parent
        radius: borderRadius
        color: "black"
        opacity: 0
    }

    TextInput {
        id: input
        anchors.left: parent.left
        anchors.leftMargin: borderRadius * .75
        anchors.right: parent.right
        anchors.rightMargin: borderRadius * .75
        anchors.verticalCenter: parent.verticalCenter
        font.pixelSize: Math.min(parent.width, parent.height) * .5
        // style: Text.Sunken
        // styleColor: "black"
        smooth: true
        selectByMouse: true
        // text: "Hello"
        onTextChanged: control.textChanged()
    }

}
