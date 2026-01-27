#pragma once

#include "Enemy.h"
#include "../Player/Player.h"

class Headron : public Enemy
{
private:
    EnemyBehaviourPattern* behaviourPattern = nullptr;
    bool up;
    float limitMargin;
    float timeToPlay;
    float counterToPlay;

public:
    Headron(bool up, float _spawnDelay);
    void Start() override;
    bool OutOfLimits() override;
    void OnEnterFunction() override;
};