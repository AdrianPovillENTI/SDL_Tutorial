#pragma once
#include "MovementPattern.h"

class LinearPattern : public MovementPattern
{
	Vector2 targetPos;
	float speed;

public:
	LinearPattern(Vector2 dir, float spd) : targetPos(dir), speed(spd) { }

	void SetDirection(const Vector2& dir) { targetPos = dir; }
	Vector2 GetDelta(float dt, float elapsed, int index) override { return targetPos * speed * dt; }
};