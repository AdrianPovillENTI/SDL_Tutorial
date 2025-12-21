#include "UIStaticImages.h"

UIStaticImages::UIStaticImages(string _spritePath) : GameObject(_spritePath) {
	_transform->size = Vector2(1920.f, 1080.f);
	_transform->position = Vector2(960, 540.f);
}

