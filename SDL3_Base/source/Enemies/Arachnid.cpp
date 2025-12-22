#include "Arachnid.h"


Arachnid::Arachnid()
    : Enemy(
        2,  // speed
        1,  // health
        2,  // damage
        "resources/Player/Player.png"
    )
{
    radius = 1000;
    _hSpeed = 0;
    Start();
}

void Arachnid::Start()
{
    playOnStart = false;
    LinearPattern* linear = new LinearPattern(Vector2::Right, speed);
    SplitPattern* split = new SplitPattern(speed);
    CircularMovementPattern* circularPattern = new CircularMovementPattern(radius, speed, _hSpeed);
    JoinPattern* join = new JoinPattern(speed);

    pattern = new EnemyBehaviourPattern(
        new MultiPhasePattern({
            { linear, 320},
            { split, 60},
            { circularPattern, 600 },
            { join, 60},
            { linear, 220}
            })
    );

    Enemy::Start();
}
