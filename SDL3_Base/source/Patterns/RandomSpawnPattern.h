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
    RandomSpawnPattern ( Vector2 targetPos , float spacing = 75.f , float randomXRange = 150.f )
        : baseDirection ( targetPos.Normalized ( ) ) ,
        spacing ( spacing ) ,
        randomXRange ( randomXRange )
    {
    }

    std::vector<Vector2> GetSpawnPositions ( Vector2 origin , int count ) override
    {
        std::vector<Vector2> res;
        res.reserve ( count );

        int sign = ( rand ( ) % 2 == 0 ) ? -1 : 1;
        Vector2 dir = baseDirection;
        dir.x *= sign;

        float maxY = RM->WINDOW_HEIGHT - enemyHeight;

        for ( int i = 0; i < count; ++i )
        {
            float randomX = ( float ) ( rand ( ) % ( int ) ( randomXRange * 2 ) ) - randomXRange;
            float randomY = ( float ) ( rand ( ) % ( int ) maxY );

            Vector2 pos = origin + dir * ( spacing * i );
            pos.x += randomX;
            pos.y = randomY;

            res.push_back ( pos );
        }

        return res;
    }
};