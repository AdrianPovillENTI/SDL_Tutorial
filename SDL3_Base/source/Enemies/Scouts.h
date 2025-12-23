#pragma once
#include "Enemy.h"
//OVNIs
class Scouts : public Enemy
{
private:
    Vector2 direction;
public:
    Scouts();
    void Start() override;
    bool OutOfLimits() override;
};

