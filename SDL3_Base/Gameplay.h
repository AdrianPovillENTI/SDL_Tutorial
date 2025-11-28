#pragma once
#include "Scene.h"

class Gameplay : public Scene
{
public:
	Gameplay() = default;

	void OnEnter() override;

	void Update() override { Scene::Update(); }
	void Render() override { Scene::Render(); }
	void OnExit() override { Scene::OnExit(); }

};

