#include "Drifter.h"

Drifter::Drifter ( Vector2 _dir )
: Enemy
(
    0.5f + ( rand ( ) % 12 ) / 10.f,
    3 , //Health
    1 , //Damage
    "resources/Player/Player.png" 
) ,
direction ( _dir )
{
    Start ( );
}

void Drifter::Start ( )
{
    playOnStart = true;
    LinearPattern * linearPattern = new LinearPattern ( direction , speed );

    pattern = new EnemyBehaviourPattern (
        new MultiPhasePattern ( {
            { linearPattern, 120 }
        } )
    );

    Enemy::Start ( );
}