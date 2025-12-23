#include "Boosters.h"

Boosters::Boosters(Vector2 _dir)
    : Enemy
    (
        2.5f + (rand() % 12) / 10.f,
        3, //Health
        1, //Damage
        "resources/Enemies/Imagen8.png"
    ),
    direction(_dir)
{
    Start();
}

void Boosters::Start()
{
    playOnStart = true;
    LinearPattern* linearPattern = new LinearPattern(direction, speed);

    pattern = new EnemyBehaviourPattern(
        new MultiPhasePattern({
            { linearPattern, 120 }
            })
    );

    Enemy::Start();
}