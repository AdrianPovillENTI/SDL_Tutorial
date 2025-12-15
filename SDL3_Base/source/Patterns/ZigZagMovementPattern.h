#pragma once
#include "MovementPattern.h"
class ZigZagMovementPattern : public MovementPattern
{
private:
    Vector2 target;
    Vector2 origin;
    float amplitude;
    float speed;

public:
    ZigZagMovementPattern ( Vector2 target , Vector2 _origin ,
        float _amplitude = 5 , float _speed = 0.5f )
        : target ( target ) , amplitude ( _amplitude ) , speed ( _speed ) , origin (_origin )
    {
    }
    Vector2 GetDelta ( float dt , float elapsed , int index ) override;
};