#pragma once
#include "MovementPattern.h"
#include "../Player.h"
class LinearToPlayerMovementPattern : public MovementPattern
{
private:
    Vector2 targetPos;
    float speed;

public:
    LinearToPlayerMovementPattern ( Transform* _target, float _speed  )
        : targetPos ( _target->position ), speed(_speed )
    {
        targetPos.Normalize ( );
    }
    Vector2 GetDelta ( float dt , float elapsed , int index ) override;
};