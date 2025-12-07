#pragma once
#include "Item.h"

class Score : public Item
{
private:
	int points;

public:
	Score() : Item("resources/Items/Score.png", Item::ItemType::SCORE), points(1000) { }
	int GetScore() const { return points; }
};

