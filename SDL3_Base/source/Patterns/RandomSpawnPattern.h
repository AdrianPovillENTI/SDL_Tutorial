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
    float enemyHeight = 64.f; // AJUSTA A TU SPRITE

public:
    RandomSpawnPattern ( Vector2 direction ,
        float spacing = 75.f ,
        float randomXRange = 150.f )
        : baseDirection ( direction.Normalized ( ) ) ,
        spacing ( spacing ) ,
        randomXRange ( randomXRange )
    {
    }

    std::vector<Vector2> GetSpawnPositions ( const Vector2 & origin ,
        int count ) const override
    {
        std::vector<Vector2> res;
        res.reserve ( count );

        int sign = ( rand ( ) % 2 == 0 ) ? -1 : 1;
        Vector2 dir = baseDirection;
        dir.x *= sign;

        for ( int i = 0; i < count; ++i )
        {
            float randomX =
                ( float ) ( rand ( ) % ( int ) ( randomXRange * 2 ) ) - randomXRange;

            Vector2 pos = origin + dir * ( spacing * i );
            pos.x += randomX;

            float maxY = RM->WINDOW_HEIGHT - enemyHeight;
            if ( pos.y < 0.f ) pos.y = 0.f;
            if ( pos.y > maxY ) pos.y = maxY;

            res.push_back ( pos );
        }

        return res;
    }
};