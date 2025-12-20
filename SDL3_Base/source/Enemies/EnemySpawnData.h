#pragma once
#include "Enemy.h"
#include "../Patterns/SpawnPattern.h"
#include "../Spawner.h"
#include "../RenderManager.h"
#include <vector>
#include <cstdio>

class EnemySpawnData
{
    int id;
    SpawnPattern* spawnPattern;
    vector<Enemy*> enemies;
    Vector2 origin;
    int enemyAliveCount;
    Vector2* lastEnemyPos;
    bool canDropitem;
public:

    EnemySpawnData ( int id, Vector2 _origin , SpawnPattern* _spawnPattern , const vector<Enemy*> enemies )
        : id ( id ), origin ( _origin ) , spawnPattern ( _spawnPattern ) , enemies ( enemies ),
          enemyAliveCount ( 0 ), canDropitem ( false )
    {
    }

    int GetAliveEnemyCount ( )
    {
        return enemyAliveCount;
    }
    bool WaveFinished ( )
    {
        return enemyAliveCount <= 0;
    }

    void Update ( )
    {
        int alive = 0;
        for ( Enemy* elem : enemies )
        {
            if ( elem == nullptr ) continue;
            if ( elem->IsPendingDestroy ( ) || elem->IsDeath ( ) ) continue;
            if ( !elem->GetActive ( ) ) continue;

            alive++;
        }
        enemyAliveCount = alive;

        TryDropItem ( );
    }

    void SpawnEnemies ( )
    {
        if ( spawnPattern == nullptr ) return;

        vector<Vector2> positions = spawnPattern->GetSpawnPositions ( origin , enemies.size ( ) );
        if ( positions.size ( ) != enemies.size ( ) ) return;

        int spawned = 0;
        for ( int i = 0; i < static_cast<int>(enemies.size ( )); i++ )
        {
            Enemy* enemy = enemies [ i ];
            if ( enemy == nullptr ) continue;

            enemy->GetTransform ( )->position = positions [ i ];
            SPAWNER.SpawnObject ( enemy );
            spawned++;
            std::cout << "Spawned enemy at position: (" << enemy->GetTransform ( )->position.x << ", " << enemy->GetTransform ( )->position.y << ")\n";
        }

        int size = static_cast<int>(enemies.size ( )) - 1;
        if ( size >= 0 && enemies [ size ] != nullptr )
            lastEnemyPos = &( enemies [ size ]->GetTransform ( )->position );

        enemyAliveCount = spawned;
    }

    void DestroyWave ( )
    {
        for ( Enemy* elem : enemies )
        {
            if ( elem ) elem->Destroy ( );
        }
    }

    void TryDropItem ( )
    {
        if ( WaveFinished ( ) && canDropitem )
        {
            canDropitem = false;
        }
    }
};

