#pragma once

#include "ImageObject.h"
#include "RenderManager.h"
#include "InputManager.h"

class TestObject : public ImageObject
{
public:
	TestObject() : ImageObject("resources/xd.png", Vector2(0.0f, 0.0f), Vector2(306.0f, 562.0f)) {
		Vector2 randomPosition = Vector2(rand() % RM->WINDOW_WIDTH, rand() % RM->WINDOW_HEIGHT);
		_transform->position = Vector2 {950,490}; //Valores para pantalla
		_transform->scale = Vector2 ( 1 , 1 );
		_transform->rotation = 0;

		_physics->SetLinearDrag(0.1f);
		_physics->SetAngularDrag(0.1f);
	}
	~TestObject() {
		
	}

	void Update() override
	{
		if (IM->GetEvent(SDLK_S, DOWN))
		{
			_physics->AddForce(Vector2(0.f, 0.01f));
		}
		else if (IM->GetEvent(SDLK_R, DOWN))
		{
			_physics->AddTorque(1.f);
		}

		Object::Update(); 
	}
};
