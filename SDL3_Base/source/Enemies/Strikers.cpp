#include "Strikers.h"

Strikers::Strikers ( Vector2 _dir )
    : Enemy
    (
    6 ,
    6 , //Health
    3 , //Damage
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