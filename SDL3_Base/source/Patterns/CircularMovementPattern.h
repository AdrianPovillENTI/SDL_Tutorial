#pragma once
#include "MovementPattern.h"
class CircularMovementPattern : public MovementPattern
{
    float speed;
    float hSpeed;
    float increment;
    float offsetx;
    float offsety;
    bool xBack;
    bool yBack;
    Vector2 dir;
    bool clockWise;

public:

    CircularMovementPattern(float inc, float _speed, float _hspeed = 0, bool cW = false);
    Vector2 GetDelta(float dt, float elapsed, int index = 0) override;
};
