import QtQuick 1.1
import "../shared"

Image {
    property real value: 0.5

    id: emptyImage
    source: "images/blood-empty.png"
    fillMode: Image.PreserveAspectFit
    clip: true

    Item {
        id: cropped
        y: (1 - value) * parent.height
        width: parent.width
        height: parent.height
        clip: true

        Image {
            id: fullImage
            source: "images/blood-full.png"
            fillMode: Image.PreserveAspectFit
            y: -(1 - value) * emptyImage.height
            width: emptyImage.width
            height: emptyImage.height
        }
    }
}
