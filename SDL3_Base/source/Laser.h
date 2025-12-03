#pragma once
#include "Item.h"
class Laser : public Item
{
private:
    float damageMultiplier;
public:
    Laser ( ) : Item ( "resources/Laser.png" ) , damageMultiplier ( 1.5f ) { }

    float GetDamageMultiplier() const { return damageMultiplier; }
};
