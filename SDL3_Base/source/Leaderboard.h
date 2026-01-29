#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "UI/Button.h"
#include "TextObject.h"

class Leaderboard : public Scene
{
private:
	float scoreSpacing = 50.f;
public:
	Leaderboard() = default;

	void OnEnter() override;

	void Update() override { Scene::Update(); }
	void Render() override { Scene::Render(); }
	void OnExit() override { Scene::OnExit(); }
};
