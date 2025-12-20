#pragma once
#include "Enemy.h"
#include "../Patterns/MovementPatternData.h"
#include "../Patterns/CheckPointMovementPattern.h"
#include "../Patterns/Pattern.h"
#include "../Patterns/MultiPhasePattern.h"

class Gulper : public Enemy
{
private:
    Vector2 direction;

public:
    Gulper ( Vector2 _dir , Vector2 pos );
    void Start ( ) override;
};