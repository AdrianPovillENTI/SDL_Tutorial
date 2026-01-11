#include "CheckPointMovementPattern.h"

Vector2 CheckPointMovementPattern::GetDelta(float dt, float elapsed, int index)

{
    if (checkPoints.empty()) return Vector2::Zero;

    Vector2 checkpoint = checkPoints[curIndex];
    Vector2 targetPos = (checkpoint - *curPosition);
    targetPos.Normalize();

    if (Vector2::Distance(*curPosition, checkpoint) <= 1.f)
    {
        curIndex++;
        if (curIndex >= checkPoints.size())
        {
            curIndex = checkPoints.size() - 1;
        }
    }
    return targetPos * speed * dt;
}
