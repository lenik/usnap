// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import "../shared"

Rectangle {
    signal closed

    id: about

    radius: 15
    color: "white"
    opacity: 0.5

    Text {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        text: "关于世界语小辞典\n\n版本：1.3.1\n作者：谢继雷 <xjl@99jsj.com>"
        font.pixelSize: parent.width / 20
        color: "darkblue"
        style: Text.Sunken
        styleColor: "lightblue"
    }

    Row {
        id: navbar
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 10
        spacing: 5

        SymbolButton {
            id: close
            symbol: "circle-x"
            onClicked: about.closed()
        }
    }

}
