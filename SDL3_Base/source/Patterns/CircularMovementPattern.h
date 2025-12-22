#pragma once
#include "MovementPattern.h"
class CircularMovementPattern : public MovementPattern
{
    float radius;
    bool clockwise;
    float elapsed;     
    Vector2 center;
    float rate = 0.0f;

public:
    CircularMovementPattern ( float r , Vector2 c)
        : radius ( r ) , center ( c )
    {
        elapsed = 0;
    }

    Vector2 GetDelta ( float dt , float elapsed , int index ) override
    {
        float dx = cos ( 0.1f * dt ) * radius;
        float dy = sin ( 0.1f * dt ) * radius;
        return Vector2 ( dx , dy );
    }
    float angle = 0.f;
    Vector2 GetDelta ( float dt)
    {
        angle += 2 * dt;
        

        float dx = cos ( angle );
        float dy = sin ( angle );
        Vector2 dir = Vector2 ( dx , dy ) * radius;
        //if ( rate >= 270 ) return Vector2::Zero;
        return center + dir;
    }
};
