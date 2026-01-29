#pragma once
#include "Scene.h"


class SplashScreen : public Scene
{
public:
	SplashScreen() = default;

	void OnEnter() override;
	void Update() override;
};
