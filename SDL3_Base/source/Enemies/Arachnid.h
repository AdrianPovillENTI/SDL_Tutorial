#pragma once
#include "Enemy.h"
//SERPENTINUS ARACHNIDUS
class Arachnid : public Enemy
{
public:
    Arachnid();
    void Start() override;
    bool OutOfLimits() override;
private:
    int radius;
    int radiusReduction;
    float _hSpeed;
};

