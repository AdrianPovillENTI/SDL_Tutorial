#pragma once
#include "MovementPattern.h"
class CircularMovementPattern : public MovementPattern
{
    float speed;
    float hSpeed;
    float radius;
    float offsetx;
    float offsety;
    bool xBack;
    bool yBack;
    Vector2 dir;

public:
    CircularMovementPattern ( float r, float _speed, float _hspeed = 0 )
        : radius(1 / r), speed(_speed), hSpeed(_hspeed)
    {
        xBack = true;
        yBack = false;
        offsetx = radius;
        offsety = radius;
        dir = Vector2(1.f, 0.f);
    }

    Vector2 GetDelta(float dt, float elapsed, int index = 0)
    {
        offsetx = xBack ? -radius : radius;
        offsety = yBack ? -radius : radius;

        dir.x += offsetx;
        dir.y += offsety;

        if (xBack)
            xBack = dir.x <= -1 ? false : true;
        else
            xBack = dir.x >= 1 ? true : false;
        if (yBack)
            yBack = dir.y <= -1 ? false : true;
        else
            yBack = dir.y >= 1 ? true : false;

        return Vector2(dir.x + hSpeed, dir.y) * speed * dt;
    }
};
