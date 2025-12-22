#pragma once
#include "Enemy.h"
//SERPENTINUS ARACHNIDUS
class Arachnid : public Enemy
{
public:
    Arachnid();
    void Start() override;

private:
    int radius;
    float _hSpeed;
};

