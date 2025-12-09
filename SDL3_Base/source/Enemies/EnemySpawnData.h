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
public:

    EnemySpawnData ( int id , SpawnPattern* _spawnPattern , const vector<Enemy*> enemies )
        : id ( id ) , spawnPattern ( _spawnPattern ) , enemies ( enemies )
    { }
    void SpawnEnemies ( )
    {
        Vector2 origin = Vector2 ( RM->WINDOW_WIDTH , RM->WINDOW_HEIGHT );
        auto positions = spawnPattern->GetSpawnPositions ( origin , enemies.size ( ) );

        if ( positions.size ( ) != enemies.size ( ) ) return;

        for ( int i = 0; i < enemies.size(); i++)
        {
            enemies [ i ]->GetTransform ( )->origin = positions [ i ];
            SPAWNER.SpawnObject ( enemies [ i ] );
        }
    }
};

