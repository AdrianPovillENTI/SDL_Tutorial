#pragma once
#include "Object.h"

class ICollisionable
{
public:
	virtual void OnCollision(Object* o) = 0;
};

