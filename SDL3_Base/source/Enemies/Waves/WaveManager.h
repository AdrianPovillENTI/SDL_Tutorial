#pragma once
#include "Wave.h"
#include <vector>
#include <functional>

class WaveManager 
{
private:
    void StartWaveAtIndex(int index);

    int curIndex = 0;
    std::vector<Wave*> waves;
    bool finished = false;
    bool started = false;

public:
    std::function<void(int waveIndex)> onWaveStarted;
    std::function<void(int waveIndex)> onWaveCompleted;
    std::function<void()> onAllWavesCompleted;

    WaveManager(std::vector<Wave *>  _waves);
    WaveManager() = default;

    void Update();
    void Start(int index);

    bool IsFinished() const { return finished; }
};