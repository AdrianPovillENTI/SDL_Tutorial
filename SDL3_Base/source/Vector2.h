#pragma once

class Vector2
{
public:
	float x;
	float y;
	Vector2() :x(0.f), y(0.f) {}
	Vector2(float _x, float _y) : x(_x), y(_y) {}
<<<<<<< HEAD
=======

	void Normalize()
	{
		float length = sqrtf(x * x + y * y);
		x /= length;
		y /= length;
	}

	Vector2 const operator+(const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y);
	}
	Vector2 const operator-(const Vector2& other) const
	{
		return Vector2(x - other.x, y - other.y);
	}
	Vector2 const operator*(const float& other) const
	{
		return Vector2(x * other, y * other);
	}
	Vector2 const operator*(const Vector2& other) const
	{
		return Vector2(x * other.x, y * other.y);
	}
	Vector2 const operator/(const float& other) const
	{
		return Vector2(x / other, y / other);
	}
	Vector2 const operator/(const Vector2& other) const
	{
		return Vector2(x / other.x, y / other.y);
	}
>>>>>>> parent of 14887ae (Input Manager)
};