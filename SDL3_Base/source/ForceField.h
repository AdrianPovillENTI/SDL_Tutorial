#pragma once
#include "Item.h"

class ForceField : public Item
{
private:
	int duration;

public:
	ForceField() : Item("resources/Items/ForceField.png", Item::ItemType::FORCEFIELD), duration(600) { }

	int GetDuration() const { return duration; }
};

