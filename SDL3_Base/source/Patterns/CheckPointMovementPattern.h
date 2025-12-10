#pragma once
#include "MovementPattern.h"
#include "MovementPatternData.h"
#include <vector>
using namespace std;
class CheckPointMovementPattern : public MovementPattern
{
    Vector2* curPosition;

    MovementPatternData patternData;
#define checkPoints patternData.checkpoints

    float speed;
    mutable int curIndex;

public:

    CheckPointMovementPattern ( Vector2 * curPosition, MovementPatternData _patternData, 
        float speed )
        : curPosition ( curPosition ) , patternData( _patternData ) ,
        speed ( speed ) { }
    Vector2 GetDelta ( float dt , float elapsed , int index ) const override
    {
        if ( checkPoints.empty()) return Vector2::Zero;

        Vector2 targetPos = ( checkPoints [ curIndex ] - *curPosition );
        Vector2 direction = targetPos.Normalized ( );
        if ( Vector2::Distance ( *curPosition , targetPos ) <= 0.01f )
        {
            curIndex = ( curIndex + 1 ) % checkPoints.size ( );
        }

        return direction * speed * dt;
    }
};