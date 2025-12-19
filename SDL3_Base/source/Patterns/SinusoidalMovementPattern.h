#pragma once
#include "MovementPattern.h"
class SinusoidalMovementPattern : public MovementPattern
{
private:
    Vector2 direction;
    Vector2 center;
    float amplitude;
    float speed;

public:
    SinusoidalMovementPattern ( Vector2 direction, float _amplitude = 5 , float _speed = 5 )
        : direction ( direction ) , amplitude ( _amplitude ) , speed ( _speed )
    {
        direction.Normalize ( );
    }
    Vector2 GetDelta ( float dt , float elapsed , int index ) override;
};
