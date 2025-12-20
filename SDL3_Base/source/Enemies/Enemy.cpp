#include "Enemy.h"

void Enemy::Start ( )
{
    state = EnemyState::ON_UPDATE;
}

void Enemy::Update ( )
{

    GameObject::Update ( );
    timeElapsed += 1.f / 60.f;
    Move ( );
    if ( isDeath ) Destroy ( );
}

void Enemy::OnCollision ( Object * collided )
{
    if ( Player * p = dynamic_cast< Player * >( collided ) )
    {
        p->ReceiveDamage ( damage );
    }
}

void Enemy::Move ( )
    {
    if ( state == EnemyState::ON_UPDATE )
    {
        if ( MOVE_PATTERN != nullptr )
        {
            Vector2 delta = MOVE_PATTERN->GetDelta ( 1.f / 60.f , timeElapsed , 0 );
            delta += Vector2::Right * -0.01f;
            _transform->position += delta;
        }
    }
    else if ( _transform->position.x <= RM->WINDOW_WIDTH )
    {
        state = EnemyState::ON_UPDATE;
    }
    if ( OutOfLimits ( ) )
    {
        state = EnemyState::ON_EXIT;
        active = false;
        Destroy ( );
    }
}
bool Enemy::OutOfLimits ( )
{
    Vector2 & pos = _transform->position;
    pos = Vector2::ClampVectorX ( pos , 0.f , RM->WINDOW_WIDTH * 1.4f );
    pos = Vector2::ClampVectorY ( pos , 0.f , RM->WINDOW_HEIGHT * 1.3f );
    return ( pos.x <= 0.f || pos.x >= RM->WINDOW_WIDTH * 1.4f ||
        pos.y <= 0.f || pos.y >= RM->WINDOW_HEIGHT * 1.3f );
}

