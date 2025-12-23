#pragma once
#include "Enemy.h"
//Cohetes2
class Lifters : public Enemy
{
private:
    Vector2 direction;
public:
    Lifters ( Vector2 _dir );
    void Start ( ) override;
};

