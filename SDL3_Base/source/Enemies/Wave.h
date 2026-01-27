#pragma once
#include "Enemy.h"
#include "../Patterns/SpawnPattern.h"
#include "../Spawner.h"
#include "../RenderManager.h"
#include <vector>
#include <cstdio>
#include <functional>

class Wave
{
    int id;
    SpawnPattern * spawnPattern;
    std::vector<Enemy *> enemies;
    Vector2 origin;
    int enemyAliveCount;
    Vector2 * lastEnemyPos;
    bool canDropitem;
    bool allKilledByPlayer;
public:
    std::function<void(Enemy*)> onEnemySpawned;

    Wave( int id , Vector2 _origin , SpawnPattern * _spawnPattern , const std::vector<Enemy *> enemies );

    int GetAliveEnemyCount();
    bool WaveFinished();

    void Update();
    void SpawnEnemies();
    void DestroyWave();
    void TryDropItem();
    void EnemyDied();
};