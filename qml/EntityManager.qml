import QtQuick 2.0

QtObject {
    property var scene
    property var entities: []
    property int idinsib: 0

    function generate(PosX,PosY,Player,Score) {
        idinsib +=1
        console.log("idinsib " + idinsib)
           var component = Qt.createComponent("Entity.qml")
           entities.push(component.createObject(scene, {"idinsib":idinsib,"x": PosX, "y": PosY, "z": 0, "player": Player, "score": Score}));
       }

    function getPointed(position){
        var pointedEntity = null
        entities.forEach(function(entity){
            if (position.x >= entity.x && position.x <= entity.x+80 && position.y >= entity.y && position.y <= entity.y+80) {
                    //entity.contains(mapToItem(entity, position.x, position.y))){
                pointedEntity = entity
            }
        })
        return pointedEntity
    }


    function createParticleObjects(startX, startY, endX, endY, charge, nextplayer) {
        var particle = Qt.createComponent("Particle.qml");

        var sprite2 = particle.createObject(scene, {"x": startX-15, "y": startY-15, "endX":endX+15, "endY":endY+15, "charge":charge, "nextplayer":nextplayer});

        if (sprite2 == null) {
            // Error Handling
            console.log("Error creating object");
        }

    }



    function changeScore(startPosition){
        var startEntity;
        startEntity = getPointed(startPosition);

        var charge = startEntity.score/2;
        startEntity.score -= charge;
        return charge;

    }

    function addCharge(finX, finY, charge, nextplayer){
        //console.log(nextplayer.toString());
        //console.log(Qt.point(finX, finY));

        var finishEntity = getPointed(Qt.point(finX, finY));

        if (finishEntity && finishEntity.player){
            console.log(finishEntity.player.toString())


            if (nextplayer == finishEntity.player){
                finishEntity.score += charge;
            }
            else if(finishEntity.score < charge){
                var endScore = charge - finishEntity.score
                finishEntity.score += charge;
                finishEntity.player = nextplayer;

            } else {
                finishEntity.score -= charge;
            }
        }
    }


    function checkWinner(){
        var firstPlayer = entities[0];
        entities.forEach(function(entity){
            if (entity.player !== firstPlayer.player) {
               return false;
            }
        })
        return true;
    }
}
