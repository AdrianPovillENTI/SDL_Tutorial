#include "UIBar.h"
#include "../Spawner.h"

UIBar::UIBar(string _fillSprite, int _totalCount) : totalCount(_totalCount), GameObject(_fillSprite) {
	_transform->size = Vector2(RM->WINDOW_WIDTH, RM->WINDOW_HEIGHT);
	_transform->position = Vector2(RM->WINDOW_WIDTH / 2, RM->WINDOW_HEIGHT / 2);
}
void UIBar::RedrawBar(int fill,int max)
{
	_transform->position = Vector2(_transform->position.x + (fill - max), RM->WINDOW_HEIGHT / 2);
}

