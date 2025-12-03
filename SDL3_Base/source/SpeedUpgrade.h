#pragma once
#include "Item.h"
class SpeedUpgrade : public Item
{
private:
    float speedMultiplier;
public:
    SpeedUpgrade ( ) : Item ( "resources/SpeedUpgrade.png" ) , speedMultiplier ( 1.5f ) { }

    float GetSpeedMultiplier() const { return speedMultiplier; }
};

