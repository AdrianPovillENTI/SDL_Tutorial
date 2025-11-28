#pragma once
#include <vector>
#include "source/Object.h"

class Scene
{
protected:
	std::vector<Object*> _ui;
	std::vector<Object*> _objects;
public:
	Scene() = default;
	virtual void OnEnter() = 0;
	virtual void Update();
	virtual void Render();
	virtual void OnExit();
};

