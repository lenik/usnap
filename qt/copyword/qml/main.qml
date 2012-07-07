import QtQuick 1.1
import com.nokia.meego 1.0
import "shared"
import "contents"

PageStackWindow {
    property bool debug: false

    id: toplevel
    width: debug ? 240 : 480
    height: debug ? 400 : 854

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
        z: 10
        onClosed: about.opacity = 0

        Behavior on opacity {
            NumberAnimation {
                target: about
                properties: "opacity"
                duration: 750
                easing.type: Easing.Linear
            }
        }
    }

    initialPage: MainPage {}
}
