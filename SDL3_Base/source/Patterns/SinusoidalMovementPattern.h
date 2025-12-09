#pragma once
#include "MovementPattern.h"
class SinusoidalMovementPattern : public MovementPattern
{
private:
    Vector2 target;
    Vector2 center;
    float amplitude;
    float speed;

public:
    SinusoidalMovementPattern ( Vector2 target, float _amplitude = 5 , float _speed = 0.5f )
        : target ( target ) , amplitude ( _amplitude ) , speed ( _speed )
    {
        target.Normalize ( );
    }
    Vector2 GetDelta ( float dt , float elapsed , int index ) const override;
};
