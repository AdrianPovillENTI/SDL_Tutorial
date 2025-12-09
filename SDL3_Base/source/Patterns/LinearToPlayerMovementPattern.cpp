#include "LinearToPlayerMovementPattern.h"

Vector2 LinearToPlayerMovementPattern::GetDelta ( float dt , float elapsed , int index ) const
{
    return target * dt * speed;
}
