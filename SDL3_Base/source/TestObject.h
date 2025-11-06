#pragma once

#include "ImageObject.h"
#include "RenderManager.h"
#include "InputManager.h"

class TestObject : public ImageObject
{
public:
	TestObject() : ImageObject("resources/xd.png", Vector2(0.0f, 0.0f), Vector2(306.0f, 562.0f)) {
		Vector2 randomPosition = Vector2(rand() % RM->WINDOW_WIDTH, rand() % RM->WINDOW_HEIGHT);
		_transform->position = randomPosition;
		_transform->scale = Vector2(0.5f, 0.5f);
		_transform->rotation = 30.0f;

		_physics->SetLinearDrag(0.1f);
		_physics->SetAngularDrag(0.1f);
	}

	void Update() override
	{
		if (IM->GetEvent(SDLK_S.DOWN))
			_transform->position.y += 0.05f;
	}
}
