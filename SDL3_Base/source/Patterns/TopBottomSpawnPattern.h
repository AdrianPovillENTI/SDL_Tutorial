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
        : _topY ( 0 ), _bottomY ( RM->WINDOW_HEIGHT ), horizontalSpacing ( horizontalSpacing )
    {
    }

    std::vector<Vector2> GetSpawnPositions ( Vector2 origin , int count ) override
    {
        std::vector<Vector2> res;
        res.reserve ( count );

        if ( count <= 0 ) return res;

        int topCount = ( count + 1 ) / 2;
        int bottomCount = count - topCount;

        for ( int i = 0; i < topCount; ++i )
        {
            float xOffset = ( i - ( topCount - 1 ) / 2.0f ) * horizontalSpacing;
            res.push_back ( Vector2 ( origin.x + xOffset + horizontalSpacing * 2, 0 ) );
        }

        for ( int i = 0; i < bottomCount; ++i )
        {
            float xOffset = ( i - ( bottomCount - 1 ) / 2.0f ) * horizontalSpacing;
            res.push_back ( Vector2 ( origin.x + xOffset - horizontalSpacing * 2, _bottomY ) );
        }

        return res;
    }
};