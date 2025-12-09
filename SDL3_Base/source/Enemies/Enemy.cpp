#include "Enemy.h"

void Enemy::Start ( )
{
    if ( pattern != nullptr ) return;

    SpawnPattern * spawnPattern = pattern->GetSpawnPattern();
    if ( spawnPattern != nullptr )
    {
        auto positions = spawnPattern->GetSpawnPositions ( _transform->origin , 4 );

        if ( !positions.empty ( ) )
        {
            _transform->origin = positions [ 0 ];

        }
    }
}

void Enemy::Update ( )
{
    GameObject::Update ( );
    timeElapsed += 1 / 60;
    Move ( );
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
    if ( pattern != nullptr ) return;
    if ( state == EnemyState::ON_UPDATE )
    {
        if ( UPDATE_P != nullptr )
        {
            Vector2 delta = UPDATE_P->GetDelta ( 1 / 60 , timeElapsed , 0 );
            _transform->origin = delta;
        }
    }
    if ( EXIT_P != nullptr )
    {
        if ( EXIT_P->ShouldExit ( _transform->origin ))
        {
            state = EnemyState::ON_EXIT;
            isDeath = true;
        }
    }
}

