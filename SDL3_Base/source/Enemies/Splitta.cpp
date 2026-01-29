#include "Splitta.h"

Splitta::Splitta(int i)
    : Enemy(
        4,  // speed
        3,  // health
        2,  // damage
        "resources/Enemies/Imagen15.png"
    )
{
    index = i;
    radius = 1000;
    _hSpeed = 0;
    Start();
}

void Splitta::Start()
{
    playOnStart = false;
    LinearPattern* linear = new LinearPattern(Vector2::Right, speed);
    SplitPattern* split = new SplitPattern(speed);
    CircularMovementPattern* circularPattern = new CircularMovementPattern(radius, speed, _hSpeed);
    JoinPattern* join = new JoinPattern(speed);

    pattern = new EnemyBehaviourPattern(
        new MultiPhasePattern({
            { linear, 100},
            { split, 60},
            { circularPattern, 150 },
            { join, 60},
            { linear, 100}
            })
    );

    Enemy::Start();
}

void Splitta::Move()
{
    if (state != EnemyState::ON_UPDATE) return;
    if (!pattern) return;

    auto* movePattern = pattern->GetMovementPattern();
    if (movePattern != nullptr)
    {
        Vector2 delta = movePattern->GetDelta(1.f / 60.f, timeElapsed, index);

        _transform->position += delta;
    }

    if (OutOfLimits())
    {
        active = false;
        Destroy();
    }
}
