#include "Headron.h"
Headron::Headron(bool _up, float _spawnDelay)
    : Enemy(
        3.f,     // Speed
        1,        // Health
        2,        // Damage
        "resources/Player/Player.png"
    ), up(_up), timeToPlay(_spawnDelay)
{
    limitMargin = 50;
}

void Headron::Start()
{
    playOnStart = false;

    MovementPatternData* dataUp = new MovementPatternData({

        { -limitMargin * 2, limitMargin},
        { (float)SC_WIDTH - limitMargin, limitMargin},
        { (float)SC_WIDTH - limitMargin, (float)SC_HEIGHT / 2 - limitMargin },
        { limitMargin, (float)SC_HEIGHT / 2 - limitMargin },
        { limitMargin, (float)SC_HEIGHT / 3  },
        { (float)SC_WIDTH / 6, (float)SC_HEIGHT / 3  },
        { (float)SC_WIDTH / 6, (float)SC_HEIGHT * 2 / 3  },
        { (float)SC_WIDTH * 2 / 6, (float)SC_HEIGHT * 2 / 3 },
        { (float)SC_WIDTH * 2 / 6, (float)SC_HEIGHT / 3 },
        { (float)SC_WIDTH * 3 / 6, (float)SC_HEIGHT / 3 },
        { (float)SC_WIDTH * 3 / 6, (float)SC_HEIGHT * 2 / 3 },
        { (float)SC_WIDTH - limitMargin, (float)SC_HEIGHT * 2 / 3 },
        { (float)SC_WIDTH - limitMargin, (float)SC_HEIGHT - limitMargin},
        { - 3 * limitMargin, (float)SC_HEIGHT - limitMargin}
        });

    MovementPatternData* dataDown = new MovementPatternData({
        { -limitMargin * 2, (float)SC_HEIGHT - limitMargin},
        { (float)SC_WIDTH - limitMargin, (float)SC_HEIGHT - limitMargin},
        { (float)SC_WIDTH - limitMargin, (float)SC_HEIGHT / 2 + limitMargin },
        { limitMargin, (float)SC_HEIGHT / 2 + limitMargin },
        { limitMargin, (float)SC_HEIGHT * 2 / 3  },
        { (float)SC_WIDTH / 6, (float)SC_HEIGHT * 2 / 3  },
        { (float)SC_WIDTH / 6, (float)SC_HEIGHT / 3  },
        { (float)SC_WIDTH * 2 / 6, (float)SC_HEIGHT / 3 },
        { (float)SC_WIDTH * 2 / 6, (float)SC_HEIGHT * 2 / 3 },
        { (float)SC_WIDTH * 3 / 6, (float)SC_HEIGHT * 2/ 3 },
        { (float)SC_WIDTH * 3 / 6, (float)SC_HEIGHT / 3 },
        { (float)SC_WIDTH - limitMargin, (float)SC_HEIGHT / 3 },
        { (float)SC_WIDTH - limitMargin, limitMargin},
        { -3 * limitMargin, limitMargin}
        });

    CheckPointMovementPattern* movement = up ? 
        new CheckPointMovementPattern(&_transform->position, dataUp, speed) : 
        new CheckPointMovementPattern(&_transform->position, dataDown, speed);

    pattern = new EnemyBehaviourPattern(
        new MultiPhasePattern({
            { movement, 120 }
            })
    );
    Enemy::Start();
}

bool Headron::OutOfLimits()
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

void Headron::OnEnterFunction()
{
    counterToPlay += 1.f / 60.f;

    if (counterToPlay < timeToPlay) return;
    playOnStart = true;
    state = Enemy::EnemyState::ON_UPDATE;
}