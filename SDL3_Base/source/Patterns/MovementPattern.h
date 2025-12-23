#pragma once
#include "../Vector2.h"
#include <cmath>

class MovementPattern
{
public:
	virtual ~MovementPattern() = default;

	virtual Vector2 GetDelta(float dt, float elapsed, int index = 0) = 0;
};

class LinearPattern : public MovementPattern
{
	Vector2 targetPos;
	float speed;

public:
	LinearPattern ( Vector2 dir , float spd )
		: targetPos ( dir) , speed ( spd )
	{
	}

	void SetDirection ( const Vector2 & dir )
	{
		targetPos = dir;
	}
	Vector2 GetDelta ( float dt , float elapsed , int index ) override
	{
		return targetPos * speed * dt;
	}
};