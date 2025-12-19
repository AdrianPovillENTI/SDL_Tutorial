#pragma once
#include "SpawnPattern.h"
class LineSpawnPattern : public SpawnPattern
{
private:
    Vector2 direction;
    float _spacing;

public: 
    LineSpawnPattern ( Vector2 _direction, float spacing = 75.f )
        : direction ( _direction.Normalized ( ) ), _spacing ( spacing )
    { }

    std::vector<Vector2> GetSpawnPositions ( const Vector2 & origin , int count ) const override
    {
        std::vector<Vector2> res;
        res.reserve ( count );

        for ( int i = 0; i < count; ++i )
            res.push_back ( origin + (direction * ( _spacing * i )));

        return res;
    }
};