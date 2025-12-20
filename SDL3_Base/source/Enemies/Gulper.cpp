#include "Gulper.h"

Gulper::Gulper ( Vector2 _dir )
    : Enemy (
    2,
    1 ,
    2 ,
    "resources/Player/Player.png"
    ) ,
    direction ( _dir )
{
}
void Gulper::Start ( )
{
    Enemy::Start ( );
    LinearPattern * linearPattern = new LinearPattern ( direction , speed );

    pattern = new EnemyBehaviourPattern (
        new MultiPhasePattern ( {
            { linearPattern, 120 }
        } )
    );

}