#pragma once
#include "UI.h"

#define UIM UIManager::GetInstance()

class UIManager
{
public:
	static UIManager* GetInstance() {
		static UIManager instance;
		return &instance;
	}

	UIManager() = default;
	UIManager(UIManager&) = delete;
	UIManager& operator = (const UIManager&) = delete;
	~UIManager() {}

	void InitializeUI();
	void UpdateLifes(int lifes);
	void UpdateCannonAmmo(int ammo);
	void UpdateLaserAmmo(int ammo);
	void UpdateShield(int hp);
	void UpdateScore(int score);

private:
	UI* ui;
};

