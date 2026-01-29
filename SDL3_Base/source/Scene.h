#pragma once
#include <vector>
#include "Object.h"
#include "Enemies/Waves/WaveManager.h"

class Scene
{
protected:
	std::vector<Object*> _ui;
	std::vector<Object*> _objects;
	WaveManager* waveManager;
public:
	Scene() = default;
	virtual void OnEnter() = 0;
	virtual void Update();
	virtual void Render();
	virtual void OnExit();
};

