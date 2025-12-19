#pragma once
#include "Enemy.h"
#include "../Patterns/MovementPatternData.h"
#include "../Patterns/CheckPointMovementPattern.h"
#include "../Patterns/Pattern.h"
#include "../Patterns/MultiPhasePattern.h"

class Swirlers : public Enemy
{
private:
    EnemyBehaviourPattern * behaviourPattern = nullptr;

public:
    Swirlers ( );
    void Start ( ) override;
    void Update ( ) override;
    void Move ( ) override;
    void OnCollision ( Object * collided ) override;
};