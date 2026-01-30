#include "Gearbot.h"

Gearbot::Gearbot ( Transform * p )
    : Enemy (
    3.8f ,
    12 ,
    7 ,
    "resources/Enemy/Imagen6.png" ,
    new EnemyBehaviourPattern (
    new LinearPattern ( Vector2::Left , speed )
    )
    ) ,
    player ( p ) ,
    hasJumped ( false ) ,
    jumpForceX ( 12.0f ) ,
    jumpForceY ( 6.0f ) ,
    triggerDistanceX ( 1.5f )
{
    movePattern = static_cast< LinearPattern * >( pattern->GetMovementPattern ( ) );
}

void Gearbot::Start ( )
{
    Enemy::Start ( );
}

void Gearbot::Move ( )
{
    if ( !player ) return;

    float directionToTarget = player->position.x - _transform->position.x;
    Vector2 direction = player->position - _transform->position;

    if ( directionToTarget > 0.05f ) movePattern->SetDirection ( Vector2::Right );
    else if ( directionToTarget < -0.05f ) movePattern->SetDirection ( Vector2::Left );
    else
    {
        movePattern->SetDirection ( Vector2::Zero );
    }
    hasJumped = directionToTarget > 0.05f || directionToTarget < -0.05f;
    if ( !hasJumped )
    {
        float dir = ( directionToTarget > 0.f ) ? 1.f : -1.f;
        _physics->AddForce ( Vector2 ( 0 , speed * 1.f / 2.f * direction.Normalized ( ).y ) );
    }
    else
    {
        Enemy::Move ( );

    }
}