// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import "../shared"

Scene {
    signal began

    id: welcome

    topStyle: "sky"
    bottomStyle: "mountain"
    border {
        left: 264 * scaleRatio; top: 191 * scaleRatio
        right: 170 * scaleRatio; bottom: 0 * scaleRatio
    }

    Row {
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 30
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: screen.width * 0.03

        CoolButton {
            id: nextButton
            style: "red"
            width: screen.width * 0.5
            height: screen.height * 0.1
            // text: "Komencu!"
            text: "开始!"
            onClicked: welcome.began()
        }
    }

}
