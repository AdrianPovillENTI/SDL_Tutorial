#pragma once
#include "MovementPattern.h"

class JoinPattern : public MovementPattern
{
public:
	JoinPattern(float _speed) : speed(_speed) {

	}
	Vector2 GetDelta(float dt, float elapsed, int index = 0) override {
		Vector2 dir;
		switch (index)
		{
		case (0):
			dir = Vector2::Right;
			break;
		case (1):
			dir = Vector2::Right + Vector2::Down;
			break;
		case(2):
			dir = Vector2::Down;
			break;
		case(3):
			dir = Vector2::Down + Vector2::Left;
			break;
		case(4):
			dir = Vector2::Left;
			break;
		case(5):
			dir = Vector2::Left + Vector2::Up;
			break;
		case(6):
			dir = Vector2::Up;
			break;
		case(7):
			dir = Vector2::Up + Vector2::Right;
			break;
		default:
			break;
		}

		return dir * speed * dt;
	}
private:
	float speed;
};