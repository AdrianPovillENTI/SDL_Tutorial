#include "Gulper.h"

Gulper::Gulper ( )
    : Enemy (
    0.5f ,     // Speed
    1 ,        // Health
    2 ,        // Damage
    "resources/Player/Player.png"
    )
{
}

void Gulper::Start ( )
{
    Enemy::Start ( );
    LinearPattern * linearPattern = new LinearPattern ( Vector2::Down , 0.25f );

    pattern = new EnemyBehaviourPattern (
        new MultiPhasePattern ( {
            { linearPattern, 120 }
        } ) ,
        new ScreenBoundsExit ( 16 )
    );

}