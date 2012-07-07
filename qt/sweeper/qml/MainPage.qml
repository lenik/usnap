import QtQuick 1.1
import com.nokia.meego 1.0
import "shared"
import "contents"

Page {
    id: mainPage

    XFlipable {
        id: flip
        anchors.fill: parent

        front: Welcome {
            anchors.fill: parent
            onBegan: {
                status.level = 1;
                status.score = 0;
                status.lives = 3;
                room.createLevel(status.level);
                flip.state = "back";
                status.go();
            }
        }

        back: Item {
            anchors.fill: parent

            Room {
                id: room
                width: parent.width
                height: parent.height
                onRemoved: {
                    status.score += 100;
                    if (room.getRemainingJunks() === 0) {
                        levelUp.state = "below";
                        levelUp.state = "";
                    }
                }
            }

            GameStatus {
                id: status
                z: 100
                anchors.fill: parent
                avoidX: room.posX
                avoidY: room.posY
                onTimeout: {
                    paused = true;
                    if (status.lives <= 0) {
                        gameOver.state = "below";
                        gameOver.state = "";
                    } else {
                        status.lives--;
                        // room.createLevel(status.level);
                        status.go();
                    }
                }
            }

            PopupText {
                id: levelUp
                y: parent.height * 0.4
                height: parent.height * 0.2
                source: "contents/images/level-up.png"
                onFadeAway: {
                    levelUp.state = "fadeOut";
                    room.createLevel(++status.level);
                    status.go();
                }
            }

            PopupText {
                id: gameOver
                y: parent.height * 0.4
                height: parent.height * 0.2
                source: "contents/images/game-over.png"
                onFadeAway: {
                    gameOver.state = "fadeOut";
                    flip.state = "front";
                    // Qt.quit();
                }
            }
        } // back-Item
    } // flipable
}
