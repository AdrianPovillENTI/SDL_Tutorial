#pragma once
#include <vector>
#include "../Vector2.h"
#include "../RenderManager.h"

class SpawnPattern
{
public:
	virtual ~SpawnPattern() = default;

	// Devuelve 'count' posiciones relativas a 'origin' donde spawnear objetos.
	virtual std::vector<Vector2> GetSpawnPositions(Vector2 origin, int count) = 0;
};

