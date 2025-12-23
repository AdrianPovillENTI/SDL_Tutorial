#pragma once
#include "Arachnid.h"

class ArachnidTail : public Arachnid
{
public:
	ArachnidTail(float i) {
		_renderer->SetResourcePath("resources/Enemies/Imagen10.png");
		playOnStart = false;
		timeToPlay = i;
		counterToPlay = 0;
	};
	
	void OnCollision(Object* collided) override;
	void OnEnterFunction() override;
private:
	float timeToPlay;
	float counterToPlay;
};

