#pragma once
#include "MovementPattern.h"
#include <vector>
#include <functional>
#include "../Vector2.h"
using namespace std;
class MultiPhasePattern : public MovementPattern
{

    mutable int currentPhase = 0;
    mutable float phaseTime = 0;
    vector<Phase> phases;
public:
    struct Phase
    {
        MovementPattern * pattern;
        float duration;
    };
    MultiPhasePattern (vector<Phase> _phases )
    {
        phases = _phases;
    }

    Vector2 GetDelta ( float dt , float elapsed , int index ) const override;
    Vector2 GetDeltaOnCondition ( float dt , float elapsed, function<bool> change , int index ) const;
};

