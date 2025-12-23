#include "Angrygons.h"

Angrygons::Angrygons ( )
    : Enemy (
    2.f ,     // Speed
    1 ,        // Health
    2 ,        // Damage
    "resources/Player/Player.png"
    )
{
}

void Angrygons::Start ( )
{
    playOnStart = true;

    MovementPatternData * data = new MovementPatternData ( {
        { ( float ) SC_WIDTH / 4.f, ( float ) SC_HEIGHT / 3 },
        { ( float ) SC_WIDTH / 4.f, ( float ) SC_HEIGHT },
        { ( float ) SC_WIDTH / 3.5f, ( float ) SC_HEIGHT },
        { ( float ) SC_WIDTH / 3.5f, ( float ) SC_HEIGHT / 3 },
        { ( float ) SC_WIDTH / 3.f, ( float ) SC_HEIGHT / 3  },
        { ( float ) SC_WIDTH / 3.f, ( float ) SC_HEIGHT  },
        { ( float ) SC_WIDTH / 2.5f, ( float ) SC_HEIGHT  },
        { ( float ) SC_WIDTH / 2.5f, ( float ) SC_HEIGHT / 3  },
        { ( float ) SC_WIDTH / 2.f, ( float ) SC_HEIGHT / 3  },
        { ( float ) SC_WIDTH / 2.f, ( float ) SC_HEIGHT   },
        { ( float ) SC_WIDTH / 1.5f, ( float ) SC_HEIGHT  },
        { ( float ) SC_WIDTH / 1.5f, ( float ) SC_HEIGHT / 3  },
        { ( float ) SC_WIDTH / 1.f, ( float ) SC_HEIGHT / 3  },
        { ( float ) SC_WIDTH / 1.f, ( float ) SC_HEIGHT  },
        { ( float ) SC_WIDTH , ( float ) SC_HEIGHT  },
        { ( float ) SC_WIDTH * 2 , ( float ) SC_HEIGHT / 3  }
        } );

    CheckPointMovementPattern * movement =
        new CheckPointMovementPattern ( &_transform->position , data , speed );

    pattern = new EnemyBehaviourPattern (
        new MultiPhasePattern ( {
            { movement, 120 }
        } )
    );
    Enemy::Start ( );
}


bool Angrygons::OutOfLimits ( )
{
    float margin = 500.f;
    Vector2 pos = _transform->position;

    if ( pos.x < -margin || pos.x > SC_WIDTH * 1.4f + margin ||
        pos.y < -margin || pos.y > SC_HEIGHT * 1.5f + margin )
    {
        return true;
    }

    return false;
}
