#include "Mawler.h"

Mawler::Mawler()
    : Enemy(
        8 ,  // speed
        1,  // health
        2,  // damage
        "resources/Enemies/Imagen3.png"
    )
{
    radius = 200;
    _hSpeed = 0.8f;
    Start();
}

void Mawler::Start()
{
    playOnStart = true;
    CircularMovementPattern* circularPattern = new CircularMovementPattern(radius, -speed, _hSpeed);

    pattern = new EnemyBehaviourPattern(
        new MultiPhasePattern({
            { circularPattern, 120 }
            })
    );
 
    Enemy::Start();
}