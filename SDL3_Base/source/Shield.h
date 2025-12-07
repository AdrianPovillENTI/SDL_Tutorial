#pragma once
#include "Item.h"

class Shield : public Item
{
private:
	int healthBonus;

public:
	Shield() : Item("resources/Items/Shield.png", Item::ItemType::SHIELD), healthBonus(25) { }
	int GetHealthBonus() const { return healthBonus; }
};
