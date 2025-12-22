#pragma once
#include "Enemy.h"
//BOCAXANCLUS PATRONUS
class Mawler : public Enemy
{
public:
    Mawler();
    void Start() override;

private:
    float _hSpeed;
    int radius;
};

