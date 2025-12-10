#pragma once
#include "MovementPattern.h"
class CircularMovementPattern : public MovementPattern
{
    float radius;
    bool clockwise;
    float elapsed;        
    float rate = 0.0f;

public:
    CircularMovementPattern ( float r , bool cw )
        : radius ( r ) , clockwise ( cw )
    {
        elapsed = 0;
    }

    Vector2 GetDelta ( float dt , float elapsed , int index ) const override
    {
        float dx = cos ( 0.1f * dt ) * radius;
        float dy = sin ( 0.1f * dt ) * radius;
        return Vector2 ( dx , dy );
    }

    Vector2 GetDelta ( float dt)
    {
        float angularSpeed = 2 * 3.14f * 0.001f;
        rate += angularSpeed * dt;

        float dx = cos ( rate ) * radius;
        float dy = sin ( rate ) * radius;

        if ( rate >= 270 ) return Vector2::Zero;
        return Vector2 ( dx , dy );
    }
};
