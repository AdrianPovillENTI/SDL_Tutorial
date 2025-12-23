#pragma once
#include "Enemy.h"
//MEDUSA AMARILLA
class Drifter : public Enemy
{
private:
    Vector2 direction;
public:
    Drifter();
    void Start ( ) override;

};

