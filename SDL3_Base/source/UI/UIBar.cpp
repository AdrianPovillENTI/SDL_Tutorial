#include "UIBar.h"
#include "../Spawner.h"

UIBar::UIBar(string _fillSprite, int _totalCount) : GameObject(_fillSprite) {
	_transform->scale = Vector2::One * 2;
	_transform->size = Vector2(RM->WINDOW_WIDTH, RM->WINDOW_HEIGHT);
	_transform->position = Vector2(0, 0);
}
void UIBar::RedrawBar(int fill)
{
	_transform->position = Vector2((fill - totalCount) * 5, 0.f);
}

