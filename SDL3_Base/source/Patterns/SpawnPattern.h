#pragma once
#include <vector>
#include "../Vector2.h"

class SpawnPattern
{
public:
	virtual ~SpawnPattern() = default;

	// Devuelve 'count' posiciones relativas a 'origin' donde spawnear objetos.
	virtual std::vector<Vector2> GetSpawnPositions(const Vector2& origin, int count) const = 0;
};

