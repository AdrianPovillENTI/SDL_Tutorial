#pragma once
#include "SpawnPattern.h"

class TopBottomSpawnPattern : public SpawnPattern
{
private:
    float horizontalSpacing;

public:
    TopBottomSpawnPattern ( float _horizontalSpacing )
        : horizontalSpacing ( _horizontalSpacing ) { }

    std::vector<Vector2> GetSpawnPositions(Vector2 origin, int count) override;
};