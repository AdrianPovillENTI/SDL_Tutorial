#include "Strikers.h"

Strikers::Strikers ( Vector2 _dir )
    : Enemy
    (
    3 ,
    3 , //Health
    1 , //Damage
    "resources/Enemies/Imagen16.png"
    ) ,
    direction ( _dir )
{
    Start ( );
}

void Strikers::Start ( )
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