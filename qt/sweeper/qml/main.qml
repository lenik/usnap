import QtQuick 1.1
import com.nokia.meego 1.0
import "shared"
import "contents"

PageStackWindow {
    property bool debug: false

    id: toplevel

    width: debug ? 320 : 480
    height: debug ? 500 : 854
    initialPage: MainPage { tools: systemTools }

    ToolBarLayout {
        id: systemTools
        ToolIcon { iconId: "content-description"; onClicked:  about.opacity = 1 }
        ToolIcon { iconId: "toolbar-close"; onClicked: Qt.quit() }
    }

    About {
        id: about
        width: parent.width * 0.8
        height: parent.height * 0.25
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        opacity: 0
        z: 11
        onClosed: about.opacity = 0
    }

}
