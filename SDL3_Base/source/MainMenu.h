#pragma once
#include "Scene.h"
#include "Spawner.h"
#include "SceneManager.h"
#include "UI/Button.h"
#include "TextObject.h"

class MainMenu : public Scene
{
public:
	MainMenu() = default;

	void OnEnter() override 
	{
		Button* button = new Button([]()
			{
			 assert(SM.SetNextScene("Level1"));
             std::cout << "Button Clicked! Starting Level 1..." << std::endl;
			}
		);
		TextObject * text = new TextObject ( " Start Game ", button->GetTransform()->position + Vector2(-60, 75), Vector2::One * 2 );

		_ui.push_back(button);
		_ui.push_back ( text );

	}
	void OnExit() override {
		Scene::OnExit ( );
	}
	void Update() override {
		Scene::Update( );
	}
	void Render() override {
		Scene::Render( );
	}
};