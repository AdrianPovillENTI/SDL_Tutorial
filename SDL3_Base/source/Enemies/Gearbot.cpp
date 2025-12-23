#include "Gearbot.h"

Gearbot::Gearbot ( Player * p )
    : Enemy (
    1.8f ,
    3 ,
    1 ,
    "resources/Player/Player.png" ,
    new EnemyBehaviourPattern (
    new LinearPattern ( Vector2::Left , 1.8f )
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

    float directionToTarget = player->GetTransform ( )->position.x - _transform->position.x;
    Vector2 direction = player->GetTransform ( )->position - _transform->position;

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