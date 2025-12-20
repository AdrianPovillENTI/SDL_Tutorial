#pragma once
#include "../GameObject.h"
#include "SpawnPattern.h"
#include "MovementPattern.h"
#include "MultiPhasePattern.h"
#include "SinusoidalMovementPattern.h"
#include "CircularMovementPattern.h"
#include "CheckPointMovementPattern.h"

class EnemyBehaviourPattern
{
    MovementPattern* movementPattern;
public:

    EnemyBehaviourPattern (MovementPattern * _movePattern)
        : movementPattern ( _movePattern ) { }
    MovementPattern * GetMovementPattern ( ) const { return movementPattern; }
};

