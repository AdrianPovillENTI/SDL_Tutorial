#pragma once
#include "SpawnPattern.h"
#include <assert.h>

class CornerSpawnPattern : public SpawnPattern
{
private:
    float spacing;
    std::vector<Vector2> origins;

public:
    CornerSpawnPattern(float _spacing = 75.f);
    std::vector<Vector2> GetSpawnPositions(Vector2 origin, int count) override;
};