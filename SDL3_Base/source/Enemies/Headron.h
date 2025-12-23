#pragma once
#include "Enemy.h"
#include "../Patterns/MovementPatternData.h"
#include "../Patterns/CheckPointMovementPattern.h"
#include "../Patterns/Pattern.h"
#include "../Patterns/MultiPhasePattern.h"

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

