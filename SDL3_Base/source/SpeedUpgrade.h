#pragma once
#include "Item.h"

class SpeedUpgrade : public Item
{
private:
	float speedMultiplier;

public:
	SpeedUpgrade() : Item("resources/Items/SpeedUpgrade.png", Item::ItemType::SPEED_UPGRADE), speedMultiplier(1.5f) { }

	float GetSpeedMultiplier() const { return speedMultiplier; }
};

