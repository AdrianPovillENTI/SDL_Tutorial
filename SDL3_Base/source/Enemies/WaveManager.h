#pragma once
#include "EnemySpawnData.h"
#include <vector>
#include <iostream>

class WaveManager : public Object
{
    std::vector<EnemySpawnData *> waves;
    int curIndex;
public:
    WaveManager ( std::vector<EnemySpawnData *>  _waves , float _timeBetweenWaves = 3.0f );
    WaveManager ( );

    void Update ( ) override;
    void StartWaveAtIndex ( int index );
};