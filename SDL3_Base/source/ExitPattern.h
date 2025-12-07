#pragma once
#include "Vector2.h"
#include "RenderManager.h"

// Interfaz para decidir cuándo un objeto debe salir/destruirse
class ExitPattern
{
public:
	virtual ~ExitPattern() = default;

	// Devuelve true si la posición está fuera de la "zona válida" (debe salir)
	virtual bool ShouldExit(const Vector2& position) const = 0;
};

// Sale cuando sale de los límites de la ventana (con un margen opcional)
class ScreenBoundsExit : public ExitPattern
{
private:
	float _margin;
public:
	ScreenBoundsExit(float margin = 16.f) : _margin(margin) { }

	bool ShouldExit(const Vector2& position) const override
	{
		if (position.x < -_margin) return true;
		if (position.x > RM->WINDOW_WIDTH + _margin) return true;
		if (position.y < -_margin) return true;
		if (position.y > RM->WINDOW_HEIGHT + _margin) return true;
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

	bool ShouldExit(const Vector2& position) const override
	{
		float dx = position.x - _origin.x;
		float dy = position.y - _origin.y;
		return (dx*dx + dy*dy) > _maxDistanceSq;
	}
};
