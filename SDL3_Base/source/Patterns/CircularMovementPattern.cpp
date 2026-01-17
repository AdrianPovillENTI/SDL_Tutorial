#include "CircularMovementPattern.h"

CircularMovementPattern::CircularMovementPattern(float inc, float _speed, float _hspeed, bool cW)
    : increment(1 / inc), speed(_speed), hSpeed(_hspeed), clockWise(cW) {
    xBack = true;
    yBack = false;
    offsetx = increment;
    offsety = increment;
    dir = Vector2(clockWise ? -1.f : 1.f, 0.f);
}

Vector2 CircularMovementPattern::GetDelta(float dt, float elapsed, int index)
{
    offsetx = xBack ? -increment : increment;
    offsety = yBack ? -increment : increment;

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
