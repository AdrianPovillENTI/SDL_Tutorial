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
public:

    EnemySpawnData ( int id, Vector2 _origin , SpawnPattern* _spawnPattern , const vector<Enemy*> enemies )
        : id ( id ), origin(_origin) , spawnPattern ( _spawnPattern ) , enemies ( enemies )
    { }
    void SpawnEnemies ( )
    {
        auto positions = spawnPattern->GetSpawnPositions ( origin , enemies.size ( ) );

        if ( positions.size ( ) != enemies.size ( ) ) return;

        for ( int i = 0; i < enemies.size(); i++)
        {
            enemies [ i ]->GetTransform ( )->position = positions [ i ];
            SPAWNER.SpawnObject ( enemies [ i ] );
        }
    }
};

