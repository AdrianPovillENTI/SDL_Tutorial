#pragma once
#include "GameObject.h"
#define HALF_SCREEN_HEIGHT RM->WINDOW_HEIGHT * 0.5f

class Background : public GameObject
{
private:
	float speed;
	Vector2 offset;
public:
	Background(int index, std::string imagePath);

	void Start ( ) override { _transform->scale = Vector2 ( 15 , 15 ); }

	void SetSpeed ( float _speed ) { speed = _speed; }

	void Update() override;
};
