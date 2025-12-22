#pragma once
#include "Enemy.h"
//AMEBA
class Splitta : public Enemy
{
public:
    Splitta(int i);
    void Start ( ) override; 
    void Move() override;
private:
    float _hSpeed;
    int radius;
    int index;
};

