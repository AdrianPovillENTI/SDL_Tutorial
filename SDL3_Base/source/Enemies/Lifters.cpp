#include "Lifters.h"

Lifters::Lifters ( Vector2 _dir )
    : Enemy
    (
    2 + ( rand ( ) % 36 ) / 10.f ,
    6 , //Health
    6 , //Damage
    "resources/Enemies/Imagen12.png"
    ) ,
    direction ( _dir )
{
    Start ( );
}

void Lifters::Start ( )
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