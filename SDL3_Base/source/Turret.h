#pragma once
#include "Item.h"
#include <string>

class Turret : public Item
{
private:
	float damageMultiplier;
	float speedMultiplier;
	std::string bulletPath;

public:
	Turret() : Item("resources/Items/Turret.png", Item::ItemType::TURRET),
			   bulletPath("resources/Player/DoubleShoot/bulletSprite.png"), damageMultiplier(0.75f),
			   speedMultiplier(1.5f) { }

	float GetDamageMultiplier() const { return damageMultiplier; }
	float GetSpeedMultiplier() const { return speedMultiplier; }
	const std::string& GetBulletPath() const { return bulletPath; }
};

