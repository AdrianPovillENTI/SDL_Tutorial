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

	UIManager() { };
	UIManager(UIManager&) = delete;
	UIManager& operator = (const UIManager&) = delete;
	~UIManager() {}

	void InitializeUI();
	void UpdateLifes(int lifes);
	void UpdateCannonAmmo(int ammo, int maxAmmo);
	void UpdateLaserAmmo(int ammo, int maxAmmo);
	void UpdateShield(int hp, int maxHp);
	void UpdateScore(int score);

	UI* gameUI;
};

