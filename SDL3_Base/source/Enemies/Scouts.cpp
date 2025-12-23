#include "Scouts.h"

Scouts::Scouts() : Enemy
(
    0.5f + (rand() % 12) / 10.f,
    3, //Health
    1, //Damage
    "resources/Player/Player.png"
)
{
    direction = Vector2::Left;
    Start();
}

void Scouts::Start()
{
    playOnStart = true;
    LinearPattern* GoLeft = new LinearPattern(direction, speed);
    LinearPattern* Stop = new LinearPattern(Vector2::Zero, speed);
    LinearPattern* GoRight = new LinearPattern(direction, -speed);

    pattern = new EnemyBehaviourPattern(
        new MultiPhasePattern({
            { GoLeft, 120 },
            { Stop, 120},
            {GoRight, 120},
            {Stop, 120},
            {GoLeft, 120},
            { Stop, 120},
            {GoRight, 120}
            }));
}

bool Scouts::OutOfLimits()
{
    float margin = 200.f;
    Vector2 pos = _transform->position;

    if (pos.x < -margin || pos.x > SC_WIDTH * 1.4f + margin ||
        pos.y < -margin || pos.y > SC_HEIGHT * 1.5f + margin)
    {
        return true;
    }

    return false;
}