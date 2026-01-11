#pragma once
#include "SpawnPattern.h"

class TopBottomSpawnPattern : public SpawnPattern
{
private:
    float _topY;
    float _bottomY;
    float horizontalSpacing;

public:
    TopBottomSpawnPattern ( float horizontalSpacing = 100.f )
        : _topY ( 0 ), _bottomY ( RM->WINDOW_HEIGHT ), horizontalSpacing ( horizontalSpacing ) { }

    std::vector<Vector2> GetSpawnPositions(Vector2 origin, int count) override;
};