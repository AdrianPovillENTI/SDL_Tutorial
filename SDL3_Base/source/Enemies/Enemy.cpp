#include "Enemy.h"

void Enemy::Start ( )
{
    timeElapsed = 0.f;

    if ( playOnStart )
        state = EnemyState::ON_UPDATE;
    else
        state = EnemyState::ON_ENTER;
}

void Enemy::Update ( )
{
    OnEnterFunction ( );

    if ( state != EnemyState::ON_UPDATE )
        return;

    GameObject::Update ( );
    timeElapsed += 1.f / 15.f;;
    Move ( );

    if ( isDeath )
        Destroy ( );
}

void Enemy::OnCollision ( Object * collided )
{
    if ( Player* p = dynamic_cast<Player*>( collided ) )
        p->ReceiveDamage ( damage );
    if (Bullet* b = dynamic_cast<Bullet*>(collided))
        ReceiveDamage(b->GetDamage());
}

void Enemy::Move ( )
{
    if ( state != EnemyState::ON_UPDATE ) return;
    if ( !pattern ) return;

    auto * movePattern = pattern->GetMovementPattern ( );
    if ( movePattern != nullptr )
    {
        Vector2 delta = movePattern->GetDelta ( 1.f / 15.f , timeElapsed , 0 );
        //delta += Vector2::Left * 0.01f;

        _transform->position += delta;
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
    float margin = 80.f;
    Vector2 pos = _transform->position;

    if ( pos.x < -margin || pos.x > SC_WIDTH * 1.4f + margin ||
        pos.y < -margin || pos.y > SC_HEIGHT * 1.5f + margin )
    {
        return true;
    }

    return false;
}
void Enemy::OnEnterFunction ( )
{
    float startX = ( RM->WINDOW_WIDTH * 1.4f ) / 2.f;

    if ( state == EnemyState::ON_ENTER )
    {
        _transform->position += Vector2::Left * speed * 1.f / 15.f;;

        if ( _transform->position.x <= startX )
        {
            state = EnemyState::ON_UPDATE;
            timeElapsed = 0.f;

        }
        return;
    }


}