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
        StartWaveAtIndex ( curIndex );
    }
    WaveManager ( ) = default;
   
    void Update ( ) override
    {
        Object::Update ( );
        waves [ curIndex ]->Update ( );
        if ( curIndex >= waves.size ( ) ) curIndex = waves.size();
        if ( waves[curIndex ]->WaveFinished())
        {
            StartWaveAtIndex ( curIndex );
            if ( curIndex <= waves.size ( ) - 1 ) curIndex++;
        }
    }
    void StartWaveAtIndex ( int index )
    {
        if ( index < 0 || index >= waves.size ( ) ) return;

        waves [ index ]->SpawnEnemies ( );
    }
    void OnCollision ( Object * collided ) override { }
};

