#pragma once
#include "../Vector2.h"
#include <cmath>

class MovementPattern
{
public:
	virtual ~MovementPattern() = default;

	virtual Vector2 GetDelta(float dt, float elapsed, int index = 0) const = 0;
};

class LinearPattern : public MovementPattern
{
	Vector2 direction;
	float speed;

public:
	LinearPattern ( Vector2 dir , float spd )
		: direction ( dir) , speed ( spd )
	{
	}

	Vector2 GetDelta ( float dt , float elapsed , int index ) const override
	{
		return direction * speed * dt;
	}
};

class CircularPattern : public MovementPattern
{
    float radius;
    bool clockwise;

public:
    CircularPattern ( float r , bool cw )
        : radius ( r ) , clockwise ( cw )
    {
    }

    Vector2 GetDelta ( float dt , float elapsed , int index ) const override
    {
        float angularSpeed = 2 * 3.14159265f / 2.0f;
        float angle = angularSpeed * elapsed * ( clockwise ? -1.0f : 1.0f );

        float dx = cos ( angle ) * radius;
        float dy = sin ( angle ) * radius;

        float dxPrev = cos ( angle - angularSpeed * dt ) * radius;
        float dyPrev = sin ( angle - angularSpeed * dt ) * radius;

        return Vector2 ( dx - dxPrev , dy - dyPrev );
    }
};
class ZigZagPattern : public MovementPattern
{
    float amplitude;
    float frequency;

public:
    ZigZagPattern ( float amp , float freq )
        : amplitude ( amp ) , frequency ( freq )
    {
    }

    Vector2 GetDelta ( float dt , float elapsed , int index ) const override
    {
        float prev = sin ( ( elapsed - dt ) * frequency ) * amplitude;
        float curr = sin ( elapsed * frequency ) * amplitude;

        return Vector2 ( curr - prev , 0 );
    }
};