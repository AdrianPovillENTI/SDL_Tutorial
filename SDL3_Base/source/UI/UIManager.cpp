#include "UIManager.h"

void UIManager::InitializeUI()
{
	ui = new UI();
}

void UIManager::UpdateCannonAmmo(int ammo)
{
	ui->cannonAmmoUI->RedrawBar(ammo);
}

void UIManager::UpdateLaserAmmo(int ammo)
{
	ui->laserAmmoUI->RedrawBar(ammo);
}

void UIManager::UpdateShield(int hp)
{
	ui->shieldUI->RedrawBar(hp);
}

void UIManager::UpdateLifes(int lifes)
{
	ui->lifesUI->SetText(to_string(lifes));
}

void UIManager::UpdateScore(int score)
{
	ui->scoreUI->SetText(to_string(score));
}