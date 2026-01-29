#include "Swirlers.h"

Swirlers::Swirlers ( )
    : Enemy (
    8 ,     // Speed
    1 ,        // Health
    2 ,        // Damage
    "resources/Enemies/Imagen14.png"
    )
{
}

void Swirlers::Start ( )
{
    playOnStart = true;

    MovementPatternData * data = new MovementPatternData ( {
        { ( float ) SC_WIDTH / 3, ( float ) SC_HEIGHT / 3 },
        { ( float ) SC_WIDTH / 3 - 100, ( float ) SC_HEIGHT / 3 + 100 },
        { ( float ) SC_WIDTH / 3, ( float ) SC_HEIGHT / 3 + 200 },
        { ( float ) SC_WIDTH / 3 + 100, ( float ) SC_HEIGHT / 3 + 100  },
        { ( float ) SC_WIDTH / 3, ( float ) SC_HEIGHT / 3  },
        { ( float ) SC_WIDTH * 2, ( float ) SC_HEIGHT / 3  }
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