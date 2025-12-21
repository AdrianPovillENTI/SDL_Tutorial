#include "UIStaticImages.h"

UIStaticImages::UIStaticImages(string _spritePath) : GameObject(_spritePath) {
	_transform->size = Vector2(RM->WINDOW_WIDTH, RM->WINDOW_HEIGHT);
	_transform->position = Vector2(RM->WINDOW_WIDTH/2, RM->WINDOW_HEIGHT/2);
}

