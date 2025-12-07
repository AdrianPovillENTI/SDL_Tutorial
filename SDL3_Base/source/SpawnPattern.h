#pragma once
#include <vector>
#include "Vector2.h"

class SpawnPattern
{
public:
	virtual ~SpawnPattern() = default;

	// Devuelve 'count' posiciones relativas a 'origin' donde spawnear objetos.
	virtual std::vector<Vector2> GetSpawnPositions(const Vector2& origin, int count) const = 0;
};

class LineSpawnPattern : public SpawnPattern
{
private:
	Vector2 _direction;
	float _spacing;
public:
	LineSpawnPattern(const Vector2& direction = Vector2(1.f, 0.f), float spacing = 32.f)
		: _direction(direction), _spacing(spacing) { _direction.Normalize(); }

	std::vector<Vector2> GetSpawnPositions(const Vector2& origin, int count) const override
	{
		std::vector<Vector2> res;
		res.resize(count);
		for (int i = 0; i < count; ++i)
			res.push_back(origin + _direction * (_spacing * static_cast<float>(i)));
		return res;
	}
};

// Patrón: círculo (distribuye en circunferencia)
class CircleSpawnPattern : public SpawnPattern
{
private:
	float _radius;
public:
	CircleSpawnPattern(float radius = 64.f) : _radius(radius) { }

	std::vector<Vector2> GetSpawnPositions(const Vector2& origin, int count) const override
	{
		std::vector<Vector2> res;
		if (count <= 0) return res;
		res.resize(count);
		const float twoPi = 6.28318530718f;
		for (int i = 0; i < count; ++i)
		{
			float angle = (twoPi * i) / static_cast<float>(count);
			res.push_back(origin + Vector2(std::cos(angle) * _radius, std::sin(angle) * _radius));
		}
		return res;
	}
};