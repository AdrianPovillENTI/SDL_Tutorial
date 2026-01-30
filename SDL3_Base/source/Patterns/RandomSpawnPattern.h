#pragma once
#include "SpawnPattern.h"
#include "../RenderManager.h"
#include <cstdlib>

class RandomSpawnPattern : public SpawnPattern
{
private:
    Vector2 baseDirection;
    float spacing;
    float randomXRange;
    float enemyHeight = 64.f;

public:
    RandomSpawnPattern ( Vector2 targetPos , float spacing = 75.f , float randomXRange = 0 )
        : baseDirection ( targetPos.Normalized ( ) ) , spacing ( spacing ) , randomXRange ( randomXRange ) { }

    std::vector<Vector2> GetSpawnPositions(Vector2 origin, int count) override;
};