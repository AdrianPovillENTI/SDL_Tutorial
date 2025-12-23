#pragma once
#include "Enemy.h"
//Cohetes
class Boosters : public Enemy
{
private:
    Vector2 direction;
public:
    Boosters(Vector2 _dir);
    void Start() override;
};

