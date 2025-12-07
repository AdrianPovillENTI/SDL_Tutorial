#pragma once
#include "Item.h"
#include <string>

class Cannon : public Item
{
private:
	float damageMultiplier;
	float speedMultiplier;
	std::string bulletPath;
public:
	Cannon() : Item("resources/Items/Cannon.png", Item::ItemType::CANNON),
			   bulletPath("resources/bulletSprite.png"), damageMultiplier(2.0f),
			   speedMultiplier(0.75f) { }

	float GetDamageMultiplier() const { return damageMultiplier; }
	float GetSpeedMultiplier() const { return speedMultiplier; }
	const std::string& GetBulletPath() const { return bulletPath; }
};


