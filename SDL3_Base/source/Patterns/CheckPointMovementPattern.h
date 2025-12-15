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

    CheckPointMovementPattern ( Vector2 * curPosition, MovementPatternData* _patternData, 
        float speed )
        : curPosition ( curPosition ) , patternData( _patternData ) ,
        speed ( speed ) { }
    Vector2 GetDelta ( float dt , float elapsed , int index ) override
    {
        if ( checkPoints.empty()) return Vector2::Zero;

        Vector2 checkpoint = checkPoints [ curIndex ];
        Vector2 direction = ( checkpoint - *curPosition );
        direction.Normalize ( );

        if ( Vector2::Distance ( *curPosition , checkpoint ) <= 1.f )
        {
            curIndex++;
            if ( curIndex >= checkPoints.size ( ) )
            {
                curIndex = checkPoints.size ( ) - 1;
            }
        }

        return direction * speed * dt;
    }
};