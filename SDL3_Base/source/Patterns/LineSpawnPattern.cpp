#include "LineSpawnPattern.h"

std::vector<Vector2> LineSpawnPattern::GetSpawnPositions(Vector2 origin, int count)
{
    std::vector<Vector2> res;
    res.reserve(count);

    for (int i = 0; i < count; ++i)
        res.push_back(origin + (targetPos * (spacing * i)));

    return res;
}
