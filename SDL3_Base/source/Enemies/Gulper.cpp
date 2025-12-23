#include "Gulper.h"

Gulper::Gulper ( Vector2 _dir )
    : Enemy (
    2 ,  // speed
    1 ,  // health
    2 ,  // damage
    "resources/Enemies/Imagen7.png"
    ) ,
    targetPos ( _dir )
{
    Start ( );
}

void Gulper::Start ( )
{
    playOnStart = false;
    LinearPattern * linearPattern = new LinearPattern ( targetPos , speed );

    pattern = new EnemyBehaviourPattern (
        new MultiPhasePattern ( {
            { linearPattern, 120 }
        } )
    );

    Enemy::Start ( );
}