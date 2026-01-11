#pragma once
#include "MovementPattern.h"

class JoinPattern : public MovementPattern
{
public:
	JoinPattern(float _speed) : speed(_speed) { }
	Vector2 GetDelta(float dt, float elapsed, int index = 0) override;
private:
	float speed;
};