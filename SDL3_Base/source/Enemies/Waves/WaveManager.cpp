#include "WaveManager.h"

WaveManager::WaveManager(std::vector<Wave *> _waves)
    : curIndex(0), waves(_waves) {
    Start(curIndex);
}

void WaveManager::Start(int startIndex)
{
    started = true;
    finished = false;

    if (waves.empty())
    {
        finished = true;
        if (onAllWavesCompleted)
            onAllWavesCompleted();
        return;
    }

    curIndex = startIndex;
    if (curIndex < 0) curIndex = 0;

    if (curIndex >= (int)waves.size())
    {
        finished = true;
        if (onAllWavesCompleted)
            onAllWavesCompleted();
        return;
    }

    StartWaveAtIndex(curIndex);
}

void WaveManager::Update ( )
{
    if (!started || finished) return;
    if (waves.empty()) return;
    if (curIndex < 0) curIndex = 0;
    if (curIndex >= (int)waves.size())
    {
        finished = true;
        if (onAllWavesCompleted)
            onAllWavesCompleted();
        return;
    }

    Wave* currentWave = waves [ curIndex ];
    if (currentWave == nullptr) return;

    currentWave->Update ( );

    if (currentWave->WaveFinished())
    {
        if (onWaveCompleted)
            onWaveCompleted(curIndex);
        int nextIndex = curIndex + 1;
        if (nextIndex < (int) waves.size())
        {
            curIndex = nextIndex;
            StartWaveAtIndex (curIndex);
        }
        else
        {
            finished = true;
            if (onAllWavesCompleted) onAllWavesCompleted();
        }
    }
}

void WaveManager::StartWaveAtIndex(int index)
{
    if (index < 0 || index >= (int)waves.size()) return;

    Wave* wave = waves[index];
    if (!wave) return;

    if (onWaveStarted)
        onWaveStarted(index);

    wave->SpawnEnemies();
}