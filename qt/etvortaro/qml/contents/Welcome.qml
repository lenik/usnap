// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import "../shared"

Rectangle {
    signal began
    signal infoClicked

    id: welcome

    gradient: Gradient {
        GradientStop {
            position: 0
            color: "#7f6db9"
        }
        GradientStop {
            position: 1
            color: "#11310b"
        }
    }

    Image {
        id: logo
        width: parent.width * 0.6
        fillMode: Image.PreserveAspectFit
        anchors.left: parent.left
        anchors.leftMargin: width * 0.1
        anchors.top: parent.top
        anchors.topMargin: height * 0.1
        source: "images/et-flag.png"
    }

    Text {
        id: preamble
        anchors.top: logo.bottom
        anchors.topMargin: 15
        anchors.right: parent.right
        anchors.rightMargin: parent.width * 0.1
        text: "-- L. L. Zamenholf, 1887"
        font.pixelSize: Math.min(parent.width, parent.height) / 20
        font.italic: true
        smooth: true
        color: "lightgray"
        style: Text.Sunken
        styleColor: "black"
    }

    Text {
        id: banner
        anchors.centerIn: parent
        font {
            pixelSize: Math.min(parent.width, parent.height) / 10
            italic: true
        }
        text: "世界语小辞典"
        color: "lightgray"
        style: Text.Outline
        styleColor: "black"
    }

    Text {
        id: description
        anchors.left: parent.left
        anchors.leftMargin: parent.width * 0.05
        anchors.right: parent.right
        anchors.rightMargin: parent.width * 0.05
        anchors.bottom: parent.bottom
        anchors.bottomMargin: parent.height * 0.2
        wrapMode: Text.WrapAnywhere
        font.pixelSize: Math.min(parent.width, parent,height) / 35
        text: "世界语是一门精简、中立的人造语言。世界语非常简单易学，是目前为止最受欢迎的人造语言。Esperanto意为“希望者”，表达了对人类未来的憧憬。\n\n" +
                    "本辞典收录了常用的世界语单词和派生词12000余目，如有错误、疏漏恳请指正。：）"
        color: "gray"
    }

    Row {
        id: navbar
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 15
        anchors.right: parent.right
        anchors.rightMargin: parent.width * 0.1
        spacing: 5

        SymbolButton {
            id: info
            symbol: "circle-i"
            onClicked: welcome.infoClicked()
        }
        SymbolButton {
            id: go
            symbol: "circle-go"
            onClicked: welcome.began()
        }
    }

}
