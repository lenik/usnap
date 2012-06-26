import QtQuick 1.0

BorderImage {
    id: button

    property string symbol: "go"
    property real size: 30

    property string image: "images/" + symbol + ".png"
    property string invertImage: "images/" + symbol + "-invert.png"
    property bool inverted

    signal clicked

    width: size
    height: size
    source: inverted
                ? (state == "pressed" ? image : invertImage)
                : (state == "pressed" ? invertImage : image)

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: button.clicked()
    }

    states: State {
        name: "pressed"
        when: mouseArea.pressed == true
    }
}
