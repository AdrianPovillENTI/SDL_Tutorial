#pragma once
#include "GameObject.h"

class Background : public GameObject {
private: 
	float speed;

public:
	Background(int index, std::string imagePath) : GameObject(imagePath)
	{
		Vector2 offset = Vector2(RM->WINDOW_WIDTH * 2, RM->WINDOW_HEIGHT/2) * index;
		_transform->position = offset;
		speed = -1.f;
	}

	void Start() override { 
		_transform->scale = Vector2(16, 15);
	}

	void SetSpeed(float _speed)
	{
		speed = _speed;
	}

	void Update() override
	{
		Object::Update();
		GameObject::Update();

		_physics->AddForce(Vector2(speed, 0.f));

		float width = RM->WINDOW_WIDTH;
		float height = RM->WINDOW_HEIGHT;

		if (_transform->position.x <= -width)
		{
			_transform->position = Vector2(width * 2, height/2);
		}
	}
};
