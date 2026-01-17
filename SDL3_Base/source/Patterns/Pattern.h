#pragma once
#include "../GameObject.h"
#include "LinearMovementPattern.h"
#include "SpawnPattern.h"
#include "MovementPattern.h"
#include "MultiPhasePattern.h"
#include "SinusoidalMovementPattern.h"
#include "CircularMovementPattern.h"
#include "CheckPointMovementPattern.h"
#include "JoinPattern.h"
#include "SplitPattern.h"

class EnemyBehaviourPattern
{
    MovementPattern* movementPattern;
public:

    EnemyBehaviourPattern (MovementPattern * _movePattern)
        : movementPattern ( _movePattern ) { }
    ~EnemyBehaviourPattern() {
        delete movementPattern;
        movementPattern = nullptr;
    }

    MovementPattern * GetMovementPattern ( ) const { return movementPattern; }
};

