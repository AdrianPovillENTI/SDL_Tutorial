#pragma once
#include "MovementPattern.h"
#include "MovementPatternData.h"
#include <vector>
using namespace std;
class CheckPointMovementPattern : public MovementPattern
{
    Vector2* curPosition;

    MovementPatternData* patternData;
#define checkPoints patternData->checkpoints

    float speed;
    int curIndex;

public:

    CheckPointMovementPattern ( Vector2 * curPosition, MovementPatternData* _patternData, float speed )
        : curPosition ( curPosition ) , patternData( _patternData ) , speed ( speed ) { }
    ~CheckPointMovementPattern() override {
        delete patternData;
        patternData = nullptr;
    }
    Vector2 GetDelta(float dt, float elapsed, int index) override;
};