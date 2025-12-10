#include "SinusoidalMovementPattern.h"

Vector2 SinusoidalMovementPattern::GetDelta ( float dt , float elapsed , int index ) const
{
    Vector2 linear = direction * ( speed * dt );
    float omega = 2 * 3.14f * 0.001f; //Angular Speed
    Vector2 perpDesplacement = Vector2 ( -direction.y , direction.x );
    Vector2 delta = perpDesplacement * 
        ( amplitude * ( sin ( omega * elapsed ) - sin ( omega * ( elapsed - dt ) ) ) );
    return linear + delta;
}
