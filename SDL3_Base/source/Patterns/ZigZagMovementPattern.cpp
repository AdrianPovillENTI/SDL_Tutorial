#include "ZigZagMovementPattern.h"

Vector2 ZigZagMovementPattern::GetDelta ( float dt , float elapsed , int index ) const
{
    Vector2 linealDelta = target * speed * dt;
    Vector2 perp = Vector2 ( -target.y , target.x );
    float omega = 2 * 3.14f * speed;
    Vector2 sinusoidalDelta = perp * ( amplitude * ( sin ( omega * elapsed ) - sin ( omega * ( elapsed - dt ) ) ) );

    Vector2 delta = linealDelta + sinusoidalDelta;
    return delta;
}
