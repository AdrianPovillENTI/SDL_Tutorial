#pragma once
#include "MovementPattern.h"

class SplitPattern : public MovementPattern
{
public:
	SplitPattern(float _speed) : speed(_speed) {

	}
	Vector2 GetDelta(float dt, float elapsed, int index = 0) override;
private:
	float speed;
};
