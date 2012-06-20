import QtQuick 1.1
import "../shared"

Scene {
    signal end

    id: rolling
    title: "单词滚动记忆中……"

    Row {
        id: buttons
        spacing: 30
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: parent.height * 0.1

        CoolButton {
            id: seeScore
            text: "查看得分"
            onClicked: rolling.end()
        }
    }

}
