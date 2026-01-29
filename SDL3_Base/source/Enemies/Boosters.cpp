#include "Boosters.h"

Boosters::Boosters(Vector2 _dir)
    : Enemy
    (
        4.5f + (rand() % 65) / 10.f,
        3, //Health
        5, //Damage
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