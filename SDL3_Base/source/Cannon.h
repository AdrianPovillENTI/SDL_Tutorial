#pragma once
#include "Item.h"
class Cannon : public Item
{
private:
    float damageMultiplier;
    int speedMultiplier;
public:
    Cannon ( ) : Item ( "resources/Cannon.png" ) , damageMultiplier ( 2 ) , speedMultiplier ( 0.75f ) { }

    float GetDamageMultiplier() const { return damageMultiplier; }
    int GetSpeedMultiplier() const { return speedMultiplier; }
};


