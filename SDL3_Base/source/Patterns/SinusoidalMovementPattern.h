#pragma once
#include "MovementPattern.h"
class SinusoidalMovementPattern : public MovementPattern
{
private:
    Vector2 targetPos;
    Vector2 center;
    float amplitude;
    float speed;

public:
    SinusoidalMovementPattern ( Vector2 targetPos, float _amplitude = 5 , float _speed = 5 )
        : targetPos ( targetPos ) , amplitude ( _amplitude ) , speed ( _speed )
    {
        targetPos.Normalize ( );
    }
    Vector2 GetDelta ( float dt , float elapsed , int index ) override;
};
