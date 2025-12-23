#include "Loopers.h"

Loopers::Loopers ( float _timeToPlay, Vector2 _dir, Vector2 _origin ) : 
    Enemy( 2.5f, 3,1 , "resources/Enemies/Imagen14.png" ),
    direction ( _dir ), origin ( _origin )
{
    playOnStart = false;
    timeToPlay = _timeToPlay;
    counterToPlay = 0;
    Start ( );
};
void Loopers::Start ( )
{
    LinearPattern * linearPattern = new LinearPattern ( direction , speed );
    LinearPattern * linearPattern2 = new LinearPattern ( Vector2::Down , speed );
    CircularMovementPattern * circular = new CircularMovementPattern ( 2500,speed,0, origin != Vector2::Zero );

    pattern = new EnemyBehaviourPattern (
        new MultiPhasePattern ( {
            { linearPattern, 200 },
            { linearPattern2, 50 },
            { circular, 600 },
            { circular, 675 },
            { linearPattern, 120 }
        } )
    );

    Enemy::Start ( );
    if ( origin != Vector2::Zero ) _transform->position = origin;
}

void Loopers::OnEnterFunction ( )
{
    counterToPlay += 1.f / 60.f;

    if ( counterToPlay < timeToPlay ) return;
    playOnStart = true;
    state = Enemy::EnemyState::ON_UPDATE;
}
