#pragma once
#include "Scene.h"
class Level1 : public Scene
{
public:
	Level1 ( ) = default;

	void OnEnter ( ) override;

	void Update ( ) override { Scene::Update ( ); }
	void Render ( ) override { Scene::Render ( ); }
	void OnExit ( ) override { Scene::OnExit ( ); }
};

