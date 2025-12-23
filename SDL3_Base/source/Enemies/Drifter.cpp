#include "Drifter.h"

Drifter::Drifter()
    : Enemy
    (
        0.5f + (rand() % 12) / 10.f,
        3, //Health
        1, //Damage
        "resources/Enemies/Imagen13.png"
    )
{
    direction = Vector2::Left;
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