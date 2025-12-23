#include "Arachnid.h"


Arachnid::Arachnid()
    : Enemy(
        4,  // speed
        1,  // health
        2,  // damage
        "resources/Player/Player.png"
    )
{
    radius = 1800;
    radiusReduction = 200;
    _hSpeed = 0;
    Start();
}

void Arachnid::Start()
{
    MovementPatternData* entranceData = new MovementPatternData({
        {500.f, 100.f },
        });
    CheckPointMovementPattern* entrance = new CheckPointMovementPattern(&_transform->position, entranceData, speed);
    CircularMovementPattern* circularPattern1 = new CircularMovementPattern(radius, speed, _hSpeed);
    CircularMovementPattern* circularPattern2 = new CircularMovementPattern(radius -radiusReduction, speed, _hSpeed);
    CircularMovementPattern* circularPattern3 = new CircularMovementPattern(radius -radiusReduction * 2, speed, _hSpeed);
    CircularMovementPattern* circularPattern4 = new CircularMovementPattern(radius -radiusReduction * 3, speed, _hSpeed);
    CircularMovementPattern* circularPattern5 = new CircularMovementPattern(radius -radiusReduction * 4, speed, _hSpeed);
    MovementPatternData* exitData = new MovementPatternData({
       { (float)SC_WIDTH / 2, -100 }
        });
    CheckPointMovementPattern* exit = new CheckPointMovementPattern(&_transform->position, exitData, speed);

    pattern = new EnemyBehaviourPattern(
        new MultiPhasePattern({
            { entrance, 60},
            { circularPattern1, 500 },
            { circularPattern2, 450 },
            { circularPattern3, 400 },
            { circularPattern4, 350 },
            { circularPattern5, 300 },
            { exit, 200 }
            })
    );

    Enemy::Start();
}

bool Arachnid::OutOfLimits()
{
    float margin = 1000.f;
    Vector2 pos = _transform->position;

    if (pos.x < -margin || pos.x > SC_WIDTH * 1.4f + margin ||
        pos.y < -margin || pos.y > SC_HEIGHT * 1.5f + margin)
    {
        return true;
    }

    return false;
}
