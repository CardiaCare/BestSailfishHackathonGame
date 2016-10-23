import QtQuick 2.0

import Sailfish.Silica 1.0

Dialog {

    property string win
    id: dialog
    Label {
        text: win
        anchors.centerIn: parent
        font.pixelSize: Theme.fontSizeExtraLarge + 80
    }
    Image {
        id: back
        z:-1
        source: "pages/Background1.jpg"
    }

}
