#pragma once

#include "AABB.h"
#include "Transform.h"
#include <vector>

class Rigidbody {
private:
	std::vector<AABB*> _colliders;
	Transform* _transform;

	Vector2 _velocity;
	float _angularVelocity;

	Vector2 _acceleration;
	float _angularAcceleration;

	float _linearDrag;
	float _angularDrag;

public:
	Rigidbody(Transform* transform) 
		: _transform(transform), _velocity
};