#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "Button.h"

class MainMenu : public Scene
{
public:
	MainMenu() = default;

	void OnEnter() override {
		Button* button = new Button([]()
			{
			 SM.SetNextScene(" Gameplay ");
			}
		);
		_ui.push_back(button);

	}
	void OnExit() override {

	}
	void Update() override {

	}
	void Render() override {

	}
};