#include "RandomSpawnPattern.h"
#include <cstdlib>

std::vector<Vector2> RandomSpawnPattern::GetSpawnPositions(Vector2 origin, int count)
{
    std::vector<Vector2> positions;
    positions.reserve(count);

    for (int i = 0; i < count; ++i)
    {
        // Generar posición aleatoria en X dentro del rango
        float randomX = origin.x + ((float)rand() / RAND_MAX * randomXRange * 2.0f) - randomXRange;
        
        // Calcular posición en Y basada en el espaciado
        float yPos = origin.y - (i * spacing);
        
        positions.push_back(Vector2(randomX, yPos));
    }

    return positions;
}
