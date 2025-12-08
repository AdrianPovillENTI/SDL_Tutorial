#pragma once
#include "Item.h"
#include <string>

class Cannon : public Item
{
private:
	int ammo;
	float damageMultiplier;
	float speedMultiplier;
	vector<string> bulletAnimationSprites;
public:
	Cannon ( ) : Item ( "resources/Items/Cannon.png" , Item::ItemType::CANNON),
		damageMultiplier ( 2 ), speedMultiplier ( 0.5f ), ammo ( 0 )
	{
		bulletAnimationSprites = {
			"resources/Player/Cannon/shot_1.png",
			"resources/Player/Cannon/shot_2.png",
			"resources/Player/Cannon/shot_3.png",
			"resources/Player/Cannon/shot_4.png",
			"resources/Player/Cannon/shot_5.png"
		};
	}
	float GetDamageMultiplier() const { return damageMultiplier; }
	float GetSpeedMultiplier() const { return speedMultiplier; }
	const vector<string> GetBulletPath ( ) const { return bulletAnimationSprites; }
	void ResetAmmo ( ) { ammo = 100; }
	int GetAmmo ( ) { return ammo; }
};


