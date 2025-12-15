#include "Enemy.h"

void Enemy::Start ( )
{
    /*if ( pattern != nullptr ) return;

    SpawnPattern * spawnPattern = pattern->GetSpawnPattern();
    if ( spawnPattern != nullptr )
    {
        auto positions = spawnPattern->GetSpawnPositions ( _transform->position , 4 );

        if ( !positions.empty ( ) )
        {
            _transform->position = positions [ 0 ];

        }
    }*/
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
            _transform->position += delta;
        }
    }
    if ( EXIT_P != nullptr )
    {
        if ( EXIT_P->ShouldExit ( _transform->position ))
        {
            state = EnemyState::ON_EXIT;
            isDeath = true;
            Destroy ( );
        }
    }
}

