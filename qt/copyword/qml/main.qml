import QtQuick 1.1
import "shared"
import "contents"

Rectangle {
    id: screen

    width: 240
    height: 400

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
                    var fileName = ":/data/" + bookName + ".csv";
                    file.fileName = fileName;
                    file.open();

                    var total = file.records.length;
                    console.debug("Total Records: " + total);

                    var count = 10;
                    var table = [];
                    for (var i = 0; i < count; i++) {
                        var pick = Math.floor(Math.random() * total);
                        var other1 = Math.floor(Math.random() * total);
                        var other2 = Math.floor(Math.random() * total);
                        var record = file.records[pick];
                        var prev = file.records[pick > 0 ? pick - 1 : other1];
                        var next = file.records[pick < total - 1 ? pick + 1 : other2];

                        var entry = [
                                    record[2], // description
                                    record[0], // word
                                    record[1], // sound
                                    prev[0], // candidate-1
                                    next[0], // candidate-2
                                ];
                        table[i] = entry;
                    }
                    file.close();

                    rolling.table = table;
                    test.table = table;

                    // show rolling
                    flip1.state = "back";
                    flick.contentX = 0;
                    rolling.start();
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
                    onSkipped: {
                        flick.contentX = screen.width;
                        test.start();
                    }
                    onDone: {
                        flick.contentX = screen.width;
                        test.start();
                    }
                }

                Test {
                    id: test
                    width: screen.width
                    height: screen.height
                    onEnd: {
                        flick.contentX = screen.width * 2; // show scoreboard
                        // scoreboard.refresh();
                    }
                    onScoreChanged: {
                        scoreboard.testPassed = test.getScore();
                    }
                }

                Scoreboard {
                    id: scoreboard
                    width: screen.width
                    height: screen.height
                    onRetry: flick.contentX = 0
                    onGoBack: {
                        flip1.state = ""; // show book chooser
                        chooseBook.show();
                    }
                }
            }
        }
    }

}
