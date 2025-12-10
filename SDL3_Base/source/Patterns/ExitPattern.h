#pragma once
#include "../Vector2.h"
#include "../RenderManager.h"

// Interfaz para decidir cuándo un objeto debe salir/destruirse
class ExitPattern
{
public:
	virtual ~ExitPattern() = default;

	// Devuelve true si la posición está fuera de la "zona válida" (debe salir)
	virtual bool ShouldExit(const Vector2& origin) const = 0;
};

// Sale cuando sale de los límites de la ventana (con un margen opcional)
class ScreenBoundsExit : public ExitPattern
{
private:
	float _margin;
public:
	ScreenBoundsExit(float margin = 16.f) : _margin(margin) { }

	bool ShouldExit(const Vector2& origin) const override
	{
		if (origin.x < 0 - _margin) return true;
		if (origin.x > RM->WINDOW_WIDTH * 1.4f + _margin) return true;
		if (origin.y < 0 - _margin) return true;
		if (origin.y > RM->WINDOW_HEIGHT * 1.3f + _margin) return true;
		return false;
	}
};

// Sale cuando se supera una distancia máxima desde un punto origen dado
class DistanceExit : public ExitPattern
{
private:
	Vector2 _origin;
	float _maxDistanceSq;
public:
	DistanceExit(const Vector2& origin = Vector2::Zero, float maxDistance = 800.f)
		: _origin(origin), _maxDistanceSq(maxDistance * maxDistance) { }

	bool ShouldExit(const Vector2& origin) const override
	{
		float dx = origin.x - _origin.x;
		float dy = origin.y - _origin.y;
		return (dx*dx + dy*dy) > _maxDistanceSq;
	}
};
