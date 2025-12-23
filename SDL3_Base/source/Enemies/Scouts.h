#pragma once
#include "Enemy.h"
//OVNIs
class Scouts : public Enemy
{
private:
    Vector2 direction;
public:
    Scouts(Vector2 _dir);
    void Start() override;
    bool OutOfLimits() override;
};

