#pragma once
#include "MovementPattern.h"
#include <vector>
#include <functional>
#include "../Vector2.h"
using namespace std;
class MultiPhasePattern : public MovementPattern
{
public:
    struct Phase
    {
        MovementPattern * movePattern;
        float duration;
        Phase ( MovementPattern * m , float d )
            : movePattern ( m ) , duration ( d )
        {
        }
    };
private:
    int currentPhase = 0;
    float phaseTime = 0;
    vector<Phase> phases;
public:
    MultiPhasePattern ( std::initializer_list<Phase> list )
        : phases ( list )
    {
    }
    Vector2 GetDelta ( float dt , float elapsed , int index ) override;
    Vector2 GetDeltaOnCondition ( float dt , float elapsed, function<bool()> change , int index ) const;
};

