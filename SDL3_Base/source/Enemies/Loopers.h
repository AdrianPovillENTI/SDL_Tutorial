#pragma once
#include "Enemy.h"
//DISQUETES
class Loopers : public Enemy
{
private:
    float timeToPlay;
    float counterToPlay;
    Vector2 direction;
    Vector2 origin;
public:
    Loopers ( float i , Vector2 _dir, Vector2 _origin = Vector2::Zero );
    void Start ( ) override;
	void OnEnterFunction() override;
};

