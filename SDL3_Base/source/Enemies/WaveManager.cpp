#include "WaveManager.h"

WaveManager::WaveManager ( std::vector<EnemySpawnData *>  _waves , float _timeBetweenWaves )
    : curIndex ( 0 ) , waves ( _waves )
{
    if ( !waves.empty ( ) && waves [ 0 ] != nullptr )
        StartWaveAtIndex ( curIndex );
}

WaveManager::WaveManager ( )
    : waves ( ) , curIndex ( 0 )
{
}

void WaveManager::Update ( )
{
    Object::Update ( );

    if ( waves.empty ( ) ) return;
    if ( curIndex < 0 ) curIndex = 0;
    if ( curIndex >= ( int ) waves.size ( ) ) return;

    EnemySpawnData * current = waves [ curIndex ];
    if ( current == nullptr ) return;

    current->Update ( );
    if ( current->WaveFinished ( ) )
    {
        int nextIndex = curIndex + 1;
        if ( nextIndex < ( int ) waves.size ( ) )
        {
            curIndex = nextIndex;
            StartWaveAtIndex ( curIndex );
        }
        else
        {
            curIndex = ( int ) waves.size ( );
        }
    }
}

void WaveManager::StartWaveAtIndex ( int index )
{
    if ( index < 0 || index >= ( int ) waves.size ( ) ) return;

    EnemySpawnData * wave = waves [ index ];
    if ( wave == nullptr ) return;

    wave->SpawnEnemies ( );
}

void WaveManager::OnCollision ( Object * collided )
{
}