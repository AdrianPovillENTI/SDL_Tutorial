#pragma once
#include "Enemy.h"
#include "../Patterns/MovementPatternData.h"
#include "../Patterns/CheckPointMovementPattern.h"
#include "../Patterns/Pattern.h"
#include "../Patterns/MultiPhasePattern.h"

class Gulper : public Enemy
{
private:
    Vector2 dir;

public:
    Gulper ( Vector2 _dir );
    void Start ( ) override;
};