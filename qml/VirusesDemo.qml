import QtQuick 2.0
import Sailfish.Silica 1.0

Item {
    id: item
    width: parent.width
    height: parent.height

    EntityManager {
        id: entityManager
        scene: item
        Component.onCompleted: {
            var count = 5
            var maxW = width
            var maxH = height
            var posX, posY, player, score
            var lastPosX = 0
            var lastPosY = 0
            var i
            var playerCount = [0,0,0]
            for(i = 0; i < count; i++) {
                posX = Math.random() * (maxW - 100)
                posY = Math.random() * (maxH - 100)
                score = Math.random() * 30 + 10
                player = Math.random() * 2 + 1
                //console.log(player)
                //console.log(entityManager.collision(Qt.point(posX,posY)))
                if(i === 0) {
                    generate(posX,posY,player,score)
                }
                else {
                    if(entityManager.collision(Qt.point(posX,posY)) === false &&
                            entityManager.collision(Qt.point(posX+80,posY)) === false &&
                            entityManager.collision(Qt.point(posX,posY+80)) === false &&
                            entityManager.collision(Qt.point(posX+80,posY+80)) === false) {
                        generate(posX,posY,player,score)
                    }
                    else {
                        i = i - 1
                    }
                }

            }
        }
    }

    Controller {
        anchors.fill: parent
        z: -1
        controllerPosition: 1
        startRadius: 40
        endRadius: 50
        onHooked: {
            var entity = entityManager.getPointed(position)
            if (entity !== null) {
                var entityPosition = Qt.point(entity.x + entity.width / 2, entity.y + entity.height / 2)
                var entityPlayer = entity.player
                if (entityPlayer === 1) {
                    startPosition = entityPosition
                    endPosition = startPosition
                    status = 1

                }
            }
        }
        onMoved: {
            var entity = entityManager.getPointed(position)
            if (entity !== null) {
                var entityPosition = Qt.point(entity.x + entity.width / 2, entity.y + entity.height / 2)
                var entityPlayer = entity.player
                if (entityPlayer !== 1) {
                    endPosition = entityPosition
                    status = 2
                }
            }
            else {
                endPosition = position
                status = 1
            }

        }

    }


    property int startTime: 20

    Text {
        id: totalTime
        font.pointSize: 12
        color:"white"
        function set() {
            totalTime.text = startTime
        }
    }

    Timer {
        id: textTimer
        interval: 1000
        repeat: true
        running: true
        triggeredOnStart: true
        onTriggered: {
            if(startTime > 0){
                startTime -= 1
                totalTime.set()
                entityManager.addScore()
            } else {
                textTimer.running = false
                var winner = entityManager.checkWinner()
                pageStack.replace(Qt.resolvedUrl("./pages/FirstPage.qml"), {}, PageStackAction.Immediate);
                if (winner){
                    console.log("true");
                    pageStack.push(Qt.resolvedUrl("WinnerDialog.qml"),{"win": "Winner"})
                }else{
                    console.log("false");
                    pageStack.push(Qt.resolvedUrl("WinnerDialog.qml"),{"win": "Game ower"})

                }
            }
        }

    }
}
