#pragma once
#include "GameObject.h"
#define HALF_SCREEN_HEIGHT RM->WINDOW_HEIGHT * 0.5f

class Background : public GameObject
{
private:
	float speed;
	Vector2 offset;
public:
	Background ( int index , std::string imagePath ) : GameObject ( imagePath )
	{
		offset = Vector2 ( RM->WINDOW_WIDTH * index , HALF_SCREEN_HEIGHT );
		_transform->position = offset;
		speed = -0.25f;
	}

	void Start ( ) override
	{
		_transform->scale = Vector2 ( 16 , 15 );
	}

	void SetSpeed ( float _speed )
	{
		speed = _speed;
	}

	void Update ( ) override
	{
		Object::Update ( );
		GameObject::Update ( );

		_physics->AddForce ( Vector2::Right * speed );

		float width = RM->WINDOW_WIDTH;
		float height = RM->WINDOW_HEIGHT;

		if ( _transform->position.x <= -width )
		{
			_transform->position.x += width * 2;
		}
	}
	void OnCollision ( Object * collided ) override;
};
