#include "Floater.h"

Floater::Floater ( )
    : Enemy (
    0.5f ,     // Speed
    1 ,        // Health
    2 ,        // Damage
    "resources/Enemies/Imagen5.png"
    ) ,
    targetPos ( Vector2::Down ),
    timeToPlay ( 60 + rand ( ) % 500 )
{
}

void Floater::Start ( )
{
    playOnStart = false;

    LinearPattern * moveUp = new LinearPattern ( Vector2::Down , speed );
    LinearPattern * stop = new LinearPattern ( Vector2::Zero , 0.f );

    pattern = new EnemyBehaviourPattern (
        new MultiPhasePattern ( {
            { moveUp,  300.F },
            { stop,    150.F },
            { moveUp,  300.F },
            { stop,    150.F },
            { moveUp,  300.F },
            { stop,    150.F },
            { moveUp,  300.F },
            { stop,    150.F },
            { moveUp,  300.F },
            { stop,    150.F },
            { moveUp,  300.F },
            { stop,    150.F },
            { moveUp,  300.F },
            { stop,    150.F }
        } )
    );

    Enemy::Start ( );
}

void Floater::OnEnterFunction ( )
{
    counterToPlay += 1.f / 60.f;

    if ( counterToPlay <= timeToPlay ) return;
    playOnStart = true;
    state = Enemy::EnemyState::ON_UPDATE;
}
