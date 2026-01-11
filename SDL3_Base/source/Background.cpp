#include "Background.h"

Background::Background(int index, std::string imagePath) : GameObject(imagePath)
{
	offset = Vector2(RM->WINDOW_WIDTH * index, HALF_SCREEN_HEIGHT);
	_transform->position = offset;
	speed = -1.f;
}

void Background::Update()
{
	GameObject::Update();

	_physics->AddForce(Vector2::Right * speed);

	float width = RM->WINDOW_WIDTH;
	float height = RM->WINDOW_HEIGHT;

	if (_transform->position.x <= -width)
	{
		_transform->position.x += width * 3;
	}
}