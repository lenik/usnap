// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import "../shared"

Scene {
    signal began

    id: welcome

    CoolButton {
        id: nextButton
        style: "red"
        width: parent.width * 0.5
        height: parent.height * 0.1
        text: "Start!"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 30
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked: welcome.began()
    }

}
