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