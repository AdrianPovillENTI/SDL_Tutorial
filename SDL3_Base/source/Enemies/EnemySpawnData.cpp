#include "EnemySpawnData.h"
#include "../Item.h"

EnemySpawnData::EnemySpawnData ( int id , Vector2 _origin , SpawnPattern * _spawnPattern , const std::vector<Enemy *> enemies )
    : id ( id ) , origin ( _origin ) , spawnPattern ( _spawnPattern ) , enemies ( enemies ) ,
    enemyAliveCount ( 0 ) , canDropitem ( true ) , allKilledByPlayer ( true )
{
}

int EnemySpawnData::GetAliveEnemyCount ( )
{
    return enemyAliveCount;
}

bool EnemySpawnData::WaveFinished ( )
{
    return enemyAliveCount <= 0;
}

void EnemySpawnData::Update ( )
{
    int alive = 0;
    allKilledByPlayer = true;

    for ( Enemy * elem : enemies )
    {
        if ( !elem ) continue;

        if ( !elem->IsDeath ( ) && elem->GetActive ( ) )
        {
            alive++;
        }

        if ( elem->IsDeath ( ) && !elem->WasKilledByPlayer ( ) )
        {
            allKilledByPlayer = false;
        }
    }

    enemyAliveCount = alive;
    TryDropItem ( );
}
void EnemySpawnData::SpawnEnemies ( )
{
    if ( spawnPattern == nullptr ) return;

    std::vector<Vector2> positions = spawnPattern->GetSpawnPositions ( origin , enemies.size ( ) );
    if ( positions.size ( ) != enemies.size ( ) ) return;

    int spawned = 0;
    for ( int i = 0; i < enemies.size ( ); i++ )
    {
        Enemy * enemy = enemies [ i ];
        if ( enemy == nullptr ) continue;

        enemy->GetTransform ( )->position = positions [ i ];
        SPAWNER.SpawnObject ( enemy );
        spawned++;
        std::cout << "Spawned enemy at position: ("
            << enemy->GetTransform ( )->position.x << ", "
            << enemy->GetTransform ( )->position.y << ")\n";
    }

    int size = enemies.size ( ) - 1;
    if ( size >= 0 && enemies [ size ] != nullptr )
        lastEnemyPos = &( enemies [ size ]->GetTransform ( )->position );

    enemyAliveCount = spawned;
}

void EnemySpawnData::DestroyWave ( )
{
    for ( Enemy * elem : enemies )
    {
        if ( elem ) elem->Destroy ( );
    }
}

void EnemySpawnData::TryDropItem ( )
{
    if ( WaveFinished ( ) && canDropitem && allKilledByPlayer )
    {
        canDropitem = false;
        SPAWNER.SpawnObject ( new Item ( "resources/Items/Score.png" , *lastEnemyPos ) );
    }
}