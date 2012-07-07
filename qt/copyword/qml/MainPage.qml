import QtQuick 1.1
import com.nokia.meego 1.0
import "shared"
import "contents"

Page {
    id: mainPage
    tools: systemTools

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

                        var sound = "";
                        var description = "";
                        if (record[1].substr(0, 1) == "[") {
                            sound = record[1];
                            description = record[2];
                        } else {
                            description = record[1];
                        }
                        var entry = [
                                    description,
                                    record[0], // word
                                    sound,
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

        back: Scene {
            id: flickScene
            anchors.fill: parent
            topStyle: "sky3"
            bottomStyle: "mountain3"
            border {
                left: 210 * scaleRatio; top: 203 * scaleRatio
                right: 242 * scaleRatio; bottom: 0 * scaleRatio }

            Flickable {
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
                        width: mainPage.width
                        height: mainPage.height
                        speed: debug ? 1 : 0.3
                        onSkipped: {
                            flick.contentX = mainPage.width;
                            test.start();
                        }
                        onDone: {
                            flick.contentX = mainPage.width;
                            test.start();
                        }
                    }

                    Test {
                        id: test
                        width: mainPage.width
                        height: mainPage.height
                        onEnd: {
                            flick.contentX = mainPage.width * 2; // show scoreboard
                            // scoreboard.refresh();
                        }
                        onScoreChanged: {
                            scoreboard.testPassed = test.getScore();
                        }
                    }

                    Scoreboard {
                        id: scoreboard
                        width: mainPage.width
                        height: mainPage.height
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
}
