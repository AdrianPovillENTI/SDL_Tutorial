#include "Gulper.h"

Gulper::Gulper ( Vector2 _dir )
    : Enemy (
    10 ,  // speed
    10 ,  // health
    2 ,  // damage
    "resources/Enemies/Imagen7.png"
    ) ,
    dir ( _dir )
{
    Start ( );
}

void Gulper::Start ( )
{
    LinearPattern * horizontalMove = new LinearPattern ( Vector2::Left , 5 );
    LinearPattern * verticalMove = new LinearPattern ( dir , speed );

    pattern = new EnemyBehaviourPattern (
        new MultiPhasePattern ( {
            { horizontalMove, 200 },
            {  verticalMove, 200 }
        } )
    );

    Enemy::Start ( );
}