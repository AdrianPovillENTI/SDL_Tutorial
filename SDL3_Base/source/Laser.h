#pragma once
#include "Item.h"
class Laser : public Item
{
private:
	int ammo;
    float damageMultiplier;
    float speedMultiplier;
	vector<string> bulletAnimationSprites;
public:
	Laser ( ) : Item ( "resources/Items/Laser.png" , Item::ItemType::LASER) ,
		damageMultiplier ( 1.5f ) , speedMultiplier ( 3 ), ammo(0)
	{
		bulletAnimationSprites = {
			"resources/Player/Laser/shot_1.png",
			"resources/Player/Laser/shot_2.png",
			"resources/Player/Laser/shot_3.png",
			"resources/Player/Laser/shot_4.png",
		};
	}

    float GetDamageMultiplier() const { return damageMultiplier; }
    float GetSpeedMultiplier ( ) const { return speedMultiplier; }
	void ResetAmmo ( ) { ammo = 100; }
	int GetAmmo ( ) { return ammo; }
};
