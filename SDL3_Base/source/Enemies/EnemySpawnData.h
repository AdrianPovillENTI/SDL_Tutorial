#pragma once
#include "Enemy.h"
#include "../Patterns/SpawnPattern.h"
#include "../Spawner.h"
#include "../RenderManager.h"
class EnemySpawnData
{
    int id;
    SpawnPattern* spawnPattern;
    vector<Enemy*> enemies;
    Vector2 origin;
    int enemyAliveCount;
    Vector2 * lastEnemyPos;
public:

    EnemySpawnData ( int id, Vector2 _origin , SpawnPattern* _spawnPattern , const vector<Enemy*> enemies )
        : id ( id ), origin(_origin) , spawnPattern ( _spawnPattern ) , enemies ( enemies )
    {
    }
    void Update ( )
    {
        for ( Enemy* elem : enemies )
        {
            if ( elem->IsDeath() )continue;
            enemyAliveCount++;
        }
        if ( enemyAliveCount <= 0 )
        {
            int size = enemies.size ( ) - 1;
            //Drop item to last enemy position variable

        }
    }
    void SpawnEnemies ( )
    {
        auto positions = spawnPattern->GetSpawnPositions ( origin , enemies.size ( ) );

        if ( positions.size ( ) != enemies.size ( ) ) return;

        for ( int i = 0; i < enemies.size(); i++)
        {
            enemies [ i ]->GetTransform ( )->position = positions [ i ];
            SPAWNER.SpawnObject ( enemies [ i ] );
        }

        int size = enemies.size ( ) - 1;
        lastEnemyPos = &( enemies [ size ]->GetTransform ( )->position );
    }
};

