#pragma once
#include "Item.h"
class Turret : public Item
{
private:
    int damageMultiplier;
    int speedMultiplier;
public:
    Turret ( ) : Item ( "resources/Turret.png" ) , damageMultiplier( 0.75f ), speedMultiplier(1.5f){ }

    int GetDamageMultiplier() const { return damageMultiplier; }
    int GetSpeedMultiplier() const { return speedMultiplier; }
};

