#pragma once
#include "GameObject.h"
#include "ICollisionable.h"
#define HALF_SCREEN_HEIGHT RM->WINDOW_HEIGHT * 0.5f

class MapDecorations : public GameObject, public ICollisionable
{
private:
	enum Border{ UP, BOTTOM, COUNT };
	Border borderType;	
	float speed;
public:
	MapDecorations (std::string imagePath ) : GameObject ( imagePath )
	{
		borderType = static_cast< Border >( rand ( ) % COUNT );
		Vector2 offset = Vector2::Zero;

		switch ( borderType )
		{
			case MapDecorations::UP:
				offset = Vector2 ( rand ( ) % RM->WINDOW_WIDTH * 16 /*Background size*/ , 50 );
				_transform->rotation = rand()%2 == 0? 180:-180;
				break;
			case MapDecorations::BOTTOM:
				offset = Vector2 ( rand ( ) % RM->WINDOW_WIDTH * 16, RM->GAME_WINDOW_HEIGHT);
				_transform->rotation = rand()%2 == 0? 360:-360;
				break;
			default:
				break;
		}
		_transform->position = offset;
		speed = -2;
	}

	void Start ( ) override
	{
		_transform->scale = Vector2::One;
	}

	void SetSpeed ( float _speed )
	{
		speed = _speed;
	}

	void Update ( ) override
	{
		GameObject::Update ( );

		_physics->AddForce ( Vector2::Right * speed );
		if ( _transform->position <= Vector2::Zero ) Destroy ( );
	}
	void OnCollision ( Object * collided ) override;
};
