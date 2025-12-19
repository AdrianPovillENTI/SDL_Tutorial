#pragma once
#include "EnemySpawnData.h"
class WaveManager : public Object
{

    vector<EnemySpawnData*> waves;
    int curIndex;
    float wavesTimer = 0;
    float timeBetweenWaves = 120.0f; 
public:
    void Update ( ) override
    {
        if ( curIndex >= waves.size ( ) ) return;

        wavesTimer += 1.0f/60.0f;

        if ( wavesTimer >= timeBetweenWaves )
        {
            StartWaveAtIndex ( curIndex );
            if(curIndex <= waves.size() - 1 ) curIndex++;
            wavesTimer = 0;
        }
    }
    void StartWaveAtIndex ( int index )
    {
        if ( index < 0 || index >= waves.size ( ) ) return;

        waves [ index ]->SpawnEnemies ( );
    }
    void OnCollision ( Object * collided ) override { }

    WaveManager ( vector<EnemySpawnData *>  _waves ) :
        waves ( _waves ) , curIndex ( 0 ),
        wavesTimer ( 0 ) , timeBetweenWaves ( 3 ) { }

    WaveManager ( ) = default;
};

