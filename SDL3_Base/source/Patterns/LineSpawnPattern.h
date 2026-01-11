#pragma once
#include "SpawnPattern.h"
class LineSpawnPattern : public SpawnPattern
{
private:
    Vector2 targetPos;
    float spacing;

public: 
    LineSpawnPattern ( Vector2 _direction, float spacing = 75.f )
        : targetPos ( _direction.Normalized ( ) ), spacing ( spacing )
    { }

    std::vector<Vector2> GetSpawnPositions(Vector2 origin, int count) override;
};