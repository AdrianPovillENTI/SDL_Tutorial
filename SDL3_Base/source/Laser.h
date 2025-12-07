#pragma once
#include "Item.h"
class Laser : public Item
{
private:
    float damageMultiplier;
    float speedMultiplier;
	vector<string> bulletAnimationSprites;
public:
	Laser ( ) : Item ( "resources/Items/Laser.png" , Item::ItemType::LASER) ,
		damageMultiplier ( 1.5f ) , speedMultiplier ( 3 )
	{
		bulletAnimationSprites = {
			"resources/Player/Laser/shot_1.png",
			"resources/Player/Laser/shot_2.png",
			"resources/Player/Laser/shot_3.png",
			"resources/Player/Laser/shot_4.png",
			"resources/Player/Laser/shot_5.png"
		};
	}

    float GetDamageMultiplier() const { return damageMultiplier; }
    float GetSpeedMultiplier ( ) const { return speedMultiplier; }
};
