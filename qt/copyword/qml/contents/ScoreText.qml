import QtQuick 1.1
import "../shared"

Text {
    property variant container

    font.pixelSize: container.width / 20
    wrapMode: Text.Wrap
}
