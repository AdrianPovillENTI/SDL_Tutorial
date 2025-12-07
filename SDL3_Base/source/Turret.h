#pragma once
#include "Item.h"
#include <string>

class Turret : public Item
{
private:
	float damageMultiplier;
	float speedMultiplier;
	vector<string> bulletAnimationSprites;

public:
	Turret() : Item("resources/Items/Turret.png", Item::ItemType::TURRET), damageMultiplier(0.75f),
			   speedMultiplier(1.5f) 
	{ 
		bulletAnimationSprites = {
			"resources/Player/Turret/shot_1.png",
			"resources/Player/Turret/shot_2.png",
			"resources/Player/Turret/shot_3.png",
			"resources/Player/Turret/shot_4.png",
			"resources/Player/Turret/shot_5.png"
        };
	}

	float GetDamageMultiplier() const { return damageMultiplier; }
	float GetSpeedMultiplier() const { return speedMultiplier; }
	const vector<string> GetBulletPath ( ) const { return bulletAnimationSprites; }
};

