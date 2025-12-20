#pragma once
#include "EnemySpawnData.h"
#include <vector>
#include <iostream>

class WaveManager : public Object
{
    std::vector<EnemySpawnData*> waves;
    int curIndex;
public:
    WaveManager ( std::vector<EnemySpawnData *>  _waves, float _timeBetweenWaves = 3.0f )
        : curIndex ( 0 ), waves(_waves) 
    { 
        if ( !waves.empty ( ) && waves [ 0 ] != nullptr )
            StartWaveAtIndex ( curIndex );
    }
    WaveManager ( ) : waves ( ), curIndex ( 0 ) { }
   
    void Update ( ) override
    {
        Object::Update ( );

        if ( waves.empty ( ) ) return;
        if ( curIndex < 0 ) curIndex = 0;
        if ( curIndex >= ( int )waves.size ( ) ) return;

        EnemySpawnData * current = waves [ curIndex ];
        if ( current == nullptr ) return;

        current->Update ( );
        if ( current->WaveFinished ( ) )
        {
            int nextIndex = curIndex + 1;
            if ( nextIndex < ( int )waves.size ( ) )
            {
                curIndex = nextIndex;
                StartWaveAtIndex ( curIndex );
            }
            else
            {
                curIndex = ( int )waves.size ( );
            }
        }
    }
    void StartWaveAtIndex ( int index )
    {
        if ( index < 0 || index >= ( int )waves.size ( ) ) return;

        EnemySpawnData * wave = waves [ index ];
        if ( wave == nullptr ) return;

        wave->SpawnEnemies ( );
    }
    void OnCollision ( Object * collided ) override { }
};

