#include "Scouts.h"

Scouts::Scouts() : Enemy
(
    7.f,
    4, //Health
    3, //Damage
    "resources/Enemies/Imagen8.png"
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
            { GoLeft, 150 },
            { Stop, 120},
            {GoRight, 150},
            {Stop, 120},
            {GoLeft, 150},
            { Stop, 120},
            {GoRight, 300}
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