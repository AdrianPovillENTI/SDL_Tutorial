#include "Mawler.h"

Mawler::Mawler()
    : Enemy(
        2,  // speed
        1,  // health
        2,  // damage
        "resources/Player/Player.png"
    )
{
    Start();
}

void Mawler::Start()
{
    playOnStart = false;
    CircularMovementPattern* circularPattern = new CircularMovementPattern(10);

    pattern = new EnemyBehaviourPattern(
        new MultiPhasePattern({
            { circularPattern, 120 }
            })
    );

    Enemy::Start();
}