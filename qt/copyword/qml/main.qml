// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import "shared"
import "contents"

Rectangle {
    id: screen

    width: 200
    height: 320

    XFlipable {
        id: flip1
        anchors.fill: parent

        front: YFlipable {
            id: front
            anchors.fill: parent

            front: Welcome {
                id: welcome
                anchors.fill: parent
                onBegan: {
                    front.state = "back"
                    chooseBook.show()
                }
            }

            back: ChooseBook {
                id: chooseBook
                anchors.fill: parent
                onChosen: {
                    flip1.state = "back"
                    flick.contentX = 0
                }
            }
        }

        back: Flickable {
            id: flick
            anchors.fill: parent
            contentWidth: row.width
            contentHeight: row.height

            Behavior on contentX {
                NumberAnimation {
                    duration: 1000
                    easing.type: Easing.OutExpo
                }
            }

            Row {
                id: row
                Rolling {
                    id: rolling
                    width: screen.width
                    height: screen.height
                    onEnd: flick.contentX = screen.width
                }
                Scoreboard {
                    id: scoreboard
                    width: screen.width
                    height: screen.height
                    onRetry: flick.contentX = 0
                    onGoBack: {
                        flip1.state = ""
                        chooseBook.show()
                    }
                }
            }
        }
    }


}
