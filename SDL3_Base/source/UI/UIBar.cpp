#include "UIBar.h"
#include "../Spawner.h"

UIBar::UIBar(string _fillSprite, int _totalCount) : totalCount(_totalCount), GameObject(_fillSprite) {
	_transform->size = Vector2(RM->WINDOW_WIDTH, RM->WINDOW_HEIGHT);
	_transform->position = Vector2(RM->WINDOW_WIDTH / 2, RM->WINDOW_HEIGHT / 2);
	xSize = 500;
	initialPos = _transform->position;
}

void UIBar::RedrawBar(int fill,int max)
{
	_transform->position = initialPos - Vector2((max - fill) * xSize / max, 0.f);
}

