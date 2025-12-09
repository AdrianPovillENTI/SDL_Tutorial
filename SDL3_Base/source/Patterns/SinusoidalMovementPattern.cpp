#include "SinusoidalMovementPattern.h"

Vector2 SinusoidalMovementPattern::GetDelta ( float dt , float elapsed , int index ) const
{
    float omega = 2 * 3.14f * speed; 
    Vector2 perpDesplacement = Vector2 ( -target.y , target.x );
    Vector2 delta = perpDesplacement * 
        ( amplitude * ( sin ( omega * elapsed ) - sin ( omega * ( elapsed - dt ) ) ) );
    return delta;
}
