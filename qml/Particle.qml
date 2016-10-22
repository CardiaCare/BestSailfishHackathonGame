import QtQuick 2.0

import "virusgame.js" as Logic

AnimatedImage {
    id: particleImg

    width: 30
    height: 30

    property int startX
    property int startY
    property int endX
    property int endY
    property int nextplayer
    property int charge

    source: "particles.gif"

    SequentialAnimation{
        id: parAn
        running: true
        ParallelAnimation{

            PropertyAnimation {
                target: particleImg
                property: "x"
                from: x
                to: endX
                duration: 3000
                //running: true
            }

            PropertyAnimation{
                target: particleImg
                property: "y"
                from: y
                to: endY
                duration: 3000
                //running: true
            }
        }
        PropertyAnimation {
            target: particleImg
            property: "opacity"
            to:0
            duration: 50
        }

        onRunningChanged:{
            if (!parAn.running){
                entityManager.addCharge(endX, endY, charge, nextplayer);
            }
        }
    }


    onOpacityChanged: {
        if (opacity == 0.0) {
            particleImg.destroy()
        }
    }

}

