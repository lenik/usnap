import QtQuick 1.1
import "../shared"

Item {
    property int level: 0
    property int score: 0
    property int lives: 0

    id: status

    Text {
        id: levelText
        text: "LEVEL " + level
        // font.family: "Monospace"
        font.pixelSize: 10
        color: "white"
        style: Text.Sunken
        styleColor: "black"
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.leftMargin: 3
        anchors.topMargin: 3
    }

    Text {
        id: scoreText
        text: "SCORE " + score
        // font.family
        color: "white"
        style: Text.Sunken
        styleColor: "black"
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.rightMargin: 3
        anchors.topMargin: 3
    }

    Column {
        id: lifeBar
        anchors.left: parent.left
        anchors.leftMargin: 3
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 3
        spacing: 5
        Repeater {
            model: status.lives
            Image {
                source: "images/circle-broom-100.png"
                width: 32
                height: 32
            }
        }
    }
}
