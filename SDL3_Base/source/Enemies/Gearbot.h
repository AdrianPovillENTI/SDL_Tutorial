#pragma once

#include "Enemy.h"
#include "../Player/Player.h"

class Gearbot : public Enemy
{
public:
    Gearbot ( Transform * p );

    void Start ( ) override;
    void Move ( ) override;

private:
    Transform * player;
    LinearPattern * movePattern;

    bool hasJumped;
    float jumpForceX;
    float jumpForceY;
    float triggerDistanceX;
};