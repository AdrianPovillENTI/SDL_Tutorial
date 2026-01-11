#pragma once
#include "../Vector2.h"
#include <cmath>

class MovementPattern
{
public:
	virtual ~MovementPattern() = default;
	virtual Vector2 GetDelta(float dt, float elapsed, int index = 0) = 0;
};

