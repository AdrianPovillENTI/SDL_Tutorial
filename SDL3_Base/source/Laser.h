#pragma once
#include "Item.h"
class Laser : public Item
{
private:
    float damageMultiplier;
    float speedMultiplier;
    string bulletPath;

public:
    Laser ( ) : Item ( "resources/Items/Laser.png" , Item::ItemType::LASER  ) , bulletPath ( "resources/bulletSprite.png" ) , damageMultiplier ( 1.5f ) { }

    float GetDamageMultiplier() const { return damageMultiplier; }
    float GetSpeedMultiplier ( ) const { return speedMultiplier; }
};
