#include "UIManager.h"
#include "../Score/ScoreManager.h"	

void UIManager::InitializeUI()
{
	gameUI = new UI();
	SCR.onScoreChanged = [this](int _score)
	{
		UpdateScore(_score);
	};
}

void UIManager::UpdateCannonAmmo(int ammo, int maxAmmo)
{
	gameUI->cannonAmmoUI->RedrawBar(ammo, maxAmmo);
}

void UIManager::UpdateLaserAmmo(int ammo, int maxAmmo)
{
	gameUI->laserAmmoUI->RedrawBar(ammo, maxAmmo);
}

void UIManager::UpdateShield(int hp, int maxHp)
{
	gameUI->shieldUI->RedrawBar(hp, maxHp);
}

void UIManager::UpdateLifes(int lifes)
{
	gameUI->lifesUI->SetText(to_string(lifes));
}

void UIManager::UpdateScore(int score)
{
	gameUI->scoreUI->SetText(to_string(score));
}