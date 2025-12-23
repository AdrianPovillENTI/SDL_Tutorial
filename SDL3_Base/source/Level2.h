#pragma once
#include "Scene.h"
class Level2 : public Scene
{
public:
	Level2 ( ) = default;

	void OnEnter ( ) override;

	void Update ( ) override { Scene::Update ( ); }
	void Render ( ) override { Scene::Render ( ); }
	void OnExit ( ) override { Scene::OnExit ( ); }
};

