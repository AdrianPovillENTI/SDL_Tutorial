#include "Swirlers.h"

Swirlers::Swirlers ( )
    : Enemy (
    0.5f ,     // Speed
    1 ,        // Health
    2 ,        // Damage
    "resources/Player/Player.png"
    )
{
}

void Swirlers::Start ( )
{
    Enemy::Start ( );

    MovementPatternData * data = new MovementPatternData ( {
        { ( float ) SC_WIDTH / 3, ( float ) SC_HEIGHT / 3 },
        { ( float ) SC_WIDTH / 3 - 100, ( float ) SC_HEIGHT / 3 + 100 },
        { ( float ) SC_WIDTH / 3, ( float ) SC_HEIGHT / 3 + 200 },
        { ( float ) SC_WIDTH / 3 + 100, ( float ) SC_HEIGHT / 3 + 100  },
        { ( float ) SC_WIDTH / 3, ( float ) SC_HEIGHT / 3  },
        { ( float ) SC_WIDTH * 2, ( float ) SC_HEIGHT / 3  }
        } );

    CheckPointMovementPattern * movement =
        new CheckPointMovementPattern ( &_transform->position , data , 1 );

    pattern = new EnemyBehaviourPattern (
        new MultiPhasePattern ( {
            { movement, 120 }
        } )
    );

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