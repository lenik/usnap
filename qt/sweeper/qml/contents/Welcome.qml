// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import "../shared"

Image {
    signal infoClicked
    signal began

    id: welcome
    source: "images/logo.png"
    fillMode: Image.Stretch

    MouseArea {
        anchors.fill: parent
        onClicked: {
            // opacity = 0;
            welcome.began();
        }
    }

    Behavior on opacity {
        NumberAnimation {
            duration: 1000
            easing.type: Easing.Linear
        }
    }

    Row {
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 30
        anchors.right: parent.right
        anchors.rightMargin: 30
        spacing: 10

        SymbolButton {
            id: aboutButton
            symbol: "circle-i"
            onClicked: welcome.infoClicked()
        }
    }
}
