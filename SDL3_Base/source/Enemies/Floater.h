#pragma once
#include "Enemy.h"

//Medusa roja
class Floater : public Enemy
{
private:
    float counterToPlay;
    float timeToPlay;
    Vector2 targetPos;
public:
    Floater ( );
    void Start ( ) override;
    void OnEnterFunction ( ) override;
};

