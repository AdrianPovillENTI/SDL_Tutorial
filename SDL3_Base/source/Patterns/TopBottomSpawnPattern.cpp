#include "TopBottomSpawnPattern.h"

std::vector<Vector2> TopBottomSpawnPattern::GetSpawnPositions(Vector2 origin, int count)
{
    std::vector<Vector2> spawnPoints;
    spawnPoints.reserve(count);

    for (int i = 0; i < count; i++)
    {
        if (i == 0)
            spawnPoints.push_back(Vector2(RM->WINDOW_WIDTH, 0));
        else
            spawnPoints.push_back(Vector2(RM->WINDOW_WIDTH + horizontalSpacing, RM->WINDOW_HEIGHT - 150));
    }

    return spawnPoints;
}
