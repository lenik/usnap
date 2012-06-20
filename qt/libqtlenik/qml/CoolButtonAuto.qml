import QtQuick 1.0

CoolButton {
    property variant container: parent
    id: button
    font.pixelSize:Math.min(container.width, container.height) / 15
    width: button.textWidth + 30
    height: button.textHeight + 10
}
