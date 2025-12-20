#include "Gulper.h"

Gulper::Gulper ( Vector2 _dir, Vector2 pos )
    : Enemy (
    0.5f ,
    1 ,
    2 ,
    "resources/Player/Player.png"
    ) ,
    direction ( _dir )
{
    _transform->position = pos;
}
void Gulper::Start ( )
{
    Enemy::Start ( );
    LinearPattern * linearPattern = new LinearPattern ( direction , 1.f );

    pattern = new EnemyBehaviourPattern (
        new MultiPhasePattern ( {
            { linearPattern, 120 }
        } ) ,
        new ScreenBoundsExit ( 16 )
    );

}