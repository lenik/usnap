import QtQuick 1.0

BorderImage {
    id: button

    property alias size: buttonText.font
    property string symbol: "go"
    property real size: 16

    property string image: "images/" + symbol + ".png"
    property string invertImage: "images/" + symbol + "-invert.png"

    signal clicked

    width: size
    height: size
    source: state == "pressed"
              ?  (inverted ? image : invertImage)
              : (inverted ? invertImage : image)

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: button.clicked()
    }

    states: State {
        name: "pressed"; when: mouseArea.pressed == true
    }
}
