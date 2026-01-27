#include "Wave.h"
#include "../Player/Item.h"

Wave::Wave (int id, Vector2 _origin, SpawnPattern* _spawnPattern, const std::vector<Enemy*> enemies)
    : id(id), origin(_origin), spawnPattern(_spawnPattern), enemies(enemies),
    enemyAliveCount(0), canDropitem(true), allKilledByPlayer(true) { }

int Wave::GetAliveEnemyCount()
{
    return enemyAliveCount;
}

bool Wave::WaveFinished()
{
    return enemyAliveCount <= 0;
}

void Wave::Update()
{
    allKilledByPlayer = true;

    for (Enemy * elem : enemies)
    {
        if (!elem ) continue;

        if (elem->IsPendingDestroy() && !elem->WasKilledByPlayer())
            allKilledByPlayer = false;
    }
    TryDropItem();
}
void Wave::SpawnEnemies()
{
    if (spawnPattern == nullptr) return;

    std::vector<Vector2> positions = spawnPattern->GetSpawnPositions(origin, enemies.size());
    if (positions.size() != enemies.size()) return;

    int spawned = 0;
    for (int i = 0; i < enemies.size(); i++)
    {
        Enemy * enemy = enemies [ i ];
        if ( enemy == nullptr ) continue;

        enemy->GetTransform()->position = positions[i];
        SPAWNER.SpawnObject (enemy);
        if (onEnemySpawned)
            onEnemySpawned(enemy);
        spawned++;
    }

    int size = enemies.size ( ) - 1;
    if ( size >= 0 && enemies [ size ] != nullptr )
        lastEnemyPos = &( enemies [ size ]->GetTransform ( )->position );

    enemyAliveCount = spawned;
}

void Wave::DestroyWave ( )
{
    for ( Enemy * elem : enemies )
    {
        if ( elem ) elem->Destroy ( );
    }
}

void Wave::TryDropItem ( )
{
    if ( WaveFinished ( ) && canDropitem && allKilledByPlayer )
    {
        canDropitem = false;
        SPAWNER.SpawnObject ( new Item ( "resources/Items/Score.png" , *lastEnemyPos ) );
    }
}

void Wave::EnemyDied()
{
    enemyAliveCount--;
    if (enemyAliveCount < 0) enemyAliveCount = 0;
}