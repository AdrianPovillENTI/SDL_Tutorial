#include "TopBottomSpawnPattern.h"

std::vector<Vector2> TopBottomSpawnPattern::GetSpawnPositions(Vector2 origin, int count)
{
    std::vector<Vector2> res;
    res.reserve(count);

    if (count <= 0) return res;

    int topCount = (count + 1) / 2;
    int bottomCount = count - topCount;

    for (int i = 0; i < topCount; ++i)
    {
        float xOffset = (i - (topCount - 1) / 2.0f) * horizontalSpacing;
        res.push_back(Vector2(origin.x + xOffset + horizontalSpacing * 2, 0));
    }

    for (int i = 0; i < bottomCount; ++i)
    {
        float xOffset = (i - (bottomCount - 1) / 2.0f) * horizontalSpacing;
        res.push_back(Vector2(origin.x + xOffset - horizontalSpacing * 2, _bottomY));
    }

    return res;
}
