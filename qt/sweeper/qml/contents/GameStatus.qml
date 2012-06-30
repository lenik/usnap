import QtQuick 1.1
import "../shared"

Item {
    property int level: 0
    property int score: 0
    property int lives: 0
    property real blood: 0
    property bool paused: true
    property real speed: 1000

    property real fontSize: 20
    property real avoidX
    property real avoidY

    signal timeout

    id: status

    function meet(obj, x, y) {
        if (x >= obj.x && y >= obj.y
                && x <= (obj.x + obj.width)
                && y <= (obj.y + obj.height))
            return true;
        else
            return false;
    }

    Text {
        id: levelText
        text: "LEVEL " + level
        // font.family: "Monospace"
        font.pixelSize: fontSize
        color: "white"
        style: Text.Sunken
        styleColor: "black"
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.leftMargin: 3
        anchors.topMargin: 3
        visible: !meet(levelText, avoidX, avoidY)
    }

    Text {
        id: scoreText
        text: "SCORE " + score
        // font.family
        font.pixelSize: fontSize
        color: "white"
        style: Text.Sunken
        styleColor: "black"
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.rightMargin: 3
        anchors.topMargin: 3
        visible: !meet(scoreText, avoidX, avoidY)
    }

    Row {
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
        visible: !meet(lifeBar, avoidX, avoidY)
    }

    Blood {
        id: bloodBar
        anchors.right: parent.right
        anchors.rightMargin: 3
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 3
        value: blood / 100
        visible: !meet(bloodBar, avoidX, avoidY)
    }

    Timer {
        running: !paused
        interval: speed
        repeat: true
        onTriggered:  {
            if (blood < 0)
                status.timeout();
            else
                blood--;
        }
    }

    function go() {
        blood = 100;
        paused = false;
    }
}
