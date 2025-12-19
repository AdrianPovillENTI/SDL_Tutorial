#include "LinearToPlayerMovementPattern.h"

Vector2 LinearToPlayerMovementPattern::GetDelta ( float dt , float elapsed , int index )
{
    return direction * dt * speed;
}
