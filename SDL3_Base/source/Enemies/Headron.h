#pragma once

#include "Enemy.h"
#include "../Player.h"

class Headron : public Enemy
{
public:
    Headron ( Player * p );

    void Start ( ) override;
    void Move ( ) override;

private:
    Player * player;
    LinearPattern * movePattern;

    bool hasJumped;
    float jumpForceX;
    float jumpForceY;
    float triggerDistanceX;
};