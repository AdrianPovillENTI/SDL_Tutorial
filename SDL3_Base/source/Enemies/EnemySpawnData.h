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
    Vector2 * lastEnemyPos;
    bool canDropitem;
public:

    EnemySpawnData ( int id, Vector2 _origin , SpawnPattern* _spawnPattern , const vector<Enemy*> enemies )
        : id ( id ), origin(_origin) , spawnPattern ( _spawnPattern ) , enemies ( enemies ),
          enemyAliveCount ( 0 ), canDropitem ( false )
    {
    }

    int GetAliveEnemyCount()
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
        for ( Enemy * elem : enemies )
        {
            if ( !elem->GetActive ( ) ) canDropitem = false;
            if ( elem->IsDeath() ) continue;
            alive++;
        }
        enemyAliveCount = alive;

        TryDropItem ( );
    }

    void SpawnEnemies ( )
    {
        vector<Vector2> positions = spawnPattern->GetSpawnPositions ( origin , enemies.size ( ) );

        if ( positions.size ( ) != enemies.size ( ) )return;

        for ( int i = 0; i < (int)enemies.size(); i++)
        {
            enemies [ i ]->GetTransform ( )->position = positions [ i ];
            enemies [ i ]->Start ( );
            SPAWNER.SpawnObject ( enemies [ i ] );
            std::cout << "Spawned enemy at position: (" << enemies [ i ]->GetTransform ( )->position.x << ", " << enemies [ i ]->GetTransform ( )->position.y << ")\n";
        }

        int size = (int)enemies.size ( ) - 1;
        if ( size >= 0 )
            lastEnemyPos = &( enemies [ size ]->GetTransform ( )->position );

        enemyAliveCount = (int)enemies.size();
    }

    void DestroyWave()
    {
        for ( Enemy* elem : enemies )
        {
            if ( elem ) elem->Destroy ( );
        }
    }

    void TryDropItem ( )
    {
        if ( WaveFinished () && canDropitem )
        {
            canDropitem = false;
        }
    }
};

