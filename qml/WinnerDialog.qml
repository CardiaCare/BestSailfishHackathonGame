import QtQuick 2.0

import Sailfish.Silica 1.0

Dialog {

    property string win
    id: dialog
    Label {
        text: win
        anchors.centerIn: parent
    }
}
