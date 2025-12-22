#pragma once
#include "Arachnid.h"

class ArachnidTail : public Arachnid
{
public:
	ArachnidTail(float i) : Arachnid() {
		timeToPlay = i;
		counterToPlay = 0;
	};
	
	void OnCollision(Object* collided) override;
};

