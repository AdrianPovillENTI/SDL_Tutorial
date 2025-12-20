#pragma once
#include "SpawnPattern.h"

class TopBottomSpawnPattern : public SpawnPattern
{
private:
    float _topY;
    float _bottomY;
    float _horizontalSpacing;

public:
    TopBottomSpawnPattern ( float topY = 0.f, float bottomY = RM->WINDOW_HEIGHT, float horizontalSpacing = 100.f )
        : _topY ( topY ), _bottomY ( bottomY * 1.3f ), _horizontalSpacing ( horizontalSpacing )
    {
    }

    std::vector<Vector2> GetSpawnPositions ( const Vector2 & origin , int count ) const override
    {
        std::vector<Vector2> res;
        res.reserve ( count );

        if ( count <= 0 ) return res;

        int topCount = ( count + 1 ) / 2;
        int bottomCount = count - topCount;

        for ( int i = 0; i < topCount; ++i )
        {
            float xOffset = ( i - ( topCount - 1 ) / 2.0f ) * _horizontalSpacing;
            res.push_back ( Vector2 ( origin.x + xOffset + _horizontalSpacing * 2, _topY ) );
        }

        for ( int i = 0; i < bottomCount; ++i )
        {
            float xOffset = ( i - ( bottomCount - 1 ) / 2.0f ) * _horizontalSpacing;
            res.push_back ( Vector2 ( origin.x + xOffset - _horizontalSpacing * 2, _bottomY ) );
        }

        return res;
    }
};