#include "Swirlers.h"

Swirlers::Swirlers ( )
    : Enemy (
    5.f ,     // Speed
    1 ,        // Health
    2 ,        // Damage
    "resources/Player/Player.png"
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

void Swirlers::Update ( )
{
    Enemy::Update ( );
}

void Swirlers::Move ( )
{
    Enemy::Move ( );
}

void Swirlers::OnCollision ( Object * collided )
{
    Enemy::OnCollision ( collided );
}