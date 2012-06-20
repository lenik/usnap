import QtQuick 1.1
import "../shared"

Scene {
    signal retry
    signal goBack

    id: score
    title: "本次得分"

    // SCORE TABLE ...

    Row {
        id: buttons
        spacing: 30
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: parent.height * 0.1

        CoolButton {
            id: retry
            text: "重来"
            onClicked: score.retry()
        }

        CoolButton {
            id: goBack
            text: "返回"
            onClicked: score.goBack()
        }
    }

}
