#pragma once
#include "../GameObject.h"
#include "SpawnPattern.h"
#include "MovementPattern.h"
#include "MultiPhasePattern.h"
#include "SinusoidalMovementPattern.h"
#include "CircularMovementPattern.h"
#include "CheckPointMovementPattern.h"
#include "ExitPattern.h"

class EnemyBehaviourPattern
{
    MovementPattern* movementPattern;
    ExitPattern* exitPattern;
public:

    EnemyBehaviourPattern (MovementPattern * _movePattern , ExitPattern * _exitPattern )
        : movementPattern ( _movePattern ) , exitPattern ( _exitPattern )
    { }
    MovementPattern * GetMovementPattern ( ) const { return movementPattern; }
    ExitPattern * GetExitPattern ( ) const { return exitPattern; }
};

