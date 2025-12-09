#pragma once
#include "SpawnPattern.h"
class LineSpawnPattern : public SpawnPattern
{
private:
    Vector2 target;
    float _spacing;

public:
    LineSpawnPattern ( const Vector2 & target = Vector2 ( 1.f , 0.f ) , float spacing = 32.f )
        : target ( target ) , _spacing ( spacing )
    {
        target.Normalize ( );
    }

    std::vector<Vector2> GetSpawnPositions ( const Vector2 & origin , int count ) const override
    {
        std::vector<Vector2> res;
        res.resize ( count );

        for ( int i = 0; i < count; ++i )
            res.push_back ( origin + target * ( _spacing * i ));

        return res;
    }
};