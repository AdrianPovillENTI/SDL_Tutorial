#pragma once
#include "../GameObject.h"
class UIBar : public GameObject
{
public:
	UIBar(string _fillSprite, int _totalCount);

	void RedrawBar(int fill);

private:
	int totalCount;
	string fillSprite;
};

