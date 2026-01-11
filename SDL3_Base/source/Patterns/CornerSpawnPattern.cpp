#include "CornerSpawnPattern.h"

CornerSpawnPattern::CornerSpawnPattern(float _spacing) : spacing(_spacing)
{
    origins.push_back(Vector2::One * spacing); //Corner up left
    origins.push_back(Vector2(RM->WINDOW_WIDTH - spacing, spacing)); //Corner up right
    origins.push_back(Vector2(spacing, RM->GAME_WINDOW_HEIGHT)); //Corner bottom left
    origins.push_back(Vector2(RM->WINDOW_WIDTH, RM->GAME_WINDOW_HEIGHT)); //Corner bottom right
}

std::vector<Vector2> CornerSpawnPattern::GetSpawnPositions(Vector2 origin, int count)
{
    std::vector<Vector2> res;
    res.reserve(count);

    int j = 0;

    for (int i = 0; i < count; ++i)
    {
        if (i != 0 && i % 2 == 0)
        {
            j++;
            if (j >= origins.size()) j = origins.size() - 1;
        }

        res.push_back(origins[j] + Vector2::Right * (spacing * (i % 2)));
    }

    return res;
}
