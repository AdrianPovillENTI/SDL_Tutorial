#pragma once
#include "Vector2.h"
#include <cmath>

// Interfaz para calcular desplazamiento/velocidad de un objeto en movimiento.
// Las implementaciones proporcionan el offset (delta position) para un paso de tiempo.
class MovementPattern
{
public:
	virtual ~MovementPattern() = default;

	// Devuelve el desplazamiento que deberá aplicarse en este frame
	// 'dt' es el delta time en segundos, 'elapsed' tiempo acumulado desde inicio.
	virtual Vector2 GetDelta(float dt, float elapsed, int index = 0) const = 0;
};

// Movimiento lineal (velocidad constante)
class LinearMovement : public MovementPattern
{
private:
	Vector2 _velocity;
public:
	LinearMovement(const Vector2& velocity = Vector2(100.f, 0.f)) : _velocity(velocity) { }

	Vector2 GetDelta(float dt, float /*elapsed*/, int /*index*/) const override
	{
		return _velocity * dt;
	}
};

// Movimiento senoidal (útil para enemigos/balas con oscilación)
class SineMovement : public MovementPattern
{
private:
	Vector2 _forward;
	Vector2 _perp;
	float _speed;
	float _amplitude;
	float _frequency;
public:
	SineMovement(const Vector2& forward = Vector2(100.f, 0.f), float amplitude = 20.f, float frequency = 2.f)
		: _forward(forward), _speed((forward.x*forward.x + forward.y*forward.y)),
		  _amplitude(amplitude), _frequency(frequency)
	{
		_forward.Normalize();
		_perp = Vector2(-_forward.y, _forward.x); // perpendicular
	}

	Vector2 GetDelta(float dt, float elapsed, int /*index*/) const override
	{
		Vector2 linear = _forward * (_speed * dt);
		float osc = std::sin(elapsed * _frequency * 6.28318530718f) * _amplitude;
		Vector2 lateral = _perp * (osc * dt); // small lateral offset per frame
		return linear + lateral;
	}
};
