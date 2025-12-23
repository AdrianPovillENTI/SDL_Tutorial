#pragma once
#include "Enemy.h"
//Misiles
class Strikers : public Enemy
{
private:
    Vector2 direction;
public:
    Strikers ( Vector2 _dir );
    void Start ( ) override;
};

