// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import "../shared"

Rectangle {
    signal closed

    id: about

    radius: 15
    color: "white"
    opacity: 0.5
    height: version.height + license.height + navbar.height + 50

    Text {
        id: version
        anchors.top: about.top
        anchors.topMargin: 10
        anchors.left: about.left
        anchors.leftMargin: 10
        text: "关于快乐扫地\n\n版本：1.3.0\n作者：谢继雷 <xjl@99jsj.com>\n\n"
        font.pixelSize: parent.width / 20
        color: "darkblue"
        style: Text.Sunken
        styleColor: "lightblue"
    }

    Text {
        id: license
        width: parent.width - 30
        anchors.top: version.bottom
        anchors.topMargin: 5
        anchors.left: about.left
        anchors.leftMargin: 10
        text: "此游戏由谢继雷出品。是一个模拟扫地的小游戏。\n" +
                "免责声明：本程序并非由诺基亚拥有或开发。诺基" +
                "亚不对其承担任何责任和保证，包括但并不限于其" +
                "性能，不侵犯他人知识产权或其他权利。本游戏和" +
                "服务系由谢继雷提供。"
        wrapMode: Text.WrapAnywhere
        font.pixelSize: parent.width / 25
        color: "gray"
    }

    Row {
        id: navbar
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 10
        spacing: 5

        SymbolButton {
            id: close
            symbol: "circle-x"
            onClicked: about.closed()
        }
    }

    Behavior on opacity {
        NumberAnimation {
            duration: 750
            easing.type: Easing.Linear
        }
    }
}
