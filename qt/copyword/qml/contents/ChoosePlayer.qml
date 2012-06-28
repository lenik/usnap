// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import "../shared"
import "Chooser.js" as ChooserEngine

Scene {
    signal chosen(string player)

    id: chooser
    title: "选择玩家"

}
