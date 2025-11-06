#pragma once
#include <cmath>

class Vector2
{
private:
	float Q_rsqrt ( float number )
	{
		long i;
		float x2 , y;
		const float threehalfs = 1.5F;

		x2 = number * 0.5F;
		y = number;
		i = *( long * ) &y; 
		i = 0x5f3759df - ( i >> 1 );
		y = *( float * ) &i; 
		y = y * ( threehalfs - ( x2 * y * y ) ); 

		return y; 
	}
public:
	float x;
	float y;
	Vector2() :x(0.f), y(0.f) {}
	Vector2(float _x, float _y) : x(_x), y(_y) {}

	Vector2 Zero ( ) { return Vector2 ( 0 , 0 ); };
	Vector2 One ( ) { return Vector2 ( 1 , 1 ); };
	Vector2 Left ( ) { return Vector2 ( -1 , 0 ); };
	Vector2 Up ( ) { return Vector2 ( 0 , 1 ); };
	Vector2 Down ( ) { return Vector2 ( 0, -1 ); };
	Vector2 Right ( ) { return Vector2 ( 0 , 1 ); };

	void Normalize()
	{
		float length = Q_rsqrt (x * x + y * y);
		x *= length;
		y *= length;
	}
	float Magnitude ( )
	{
		float length = Q_rsqrt ( x * x + y * y );
		return 1 / length;
	}
	float Distance ( Vector2 from , Vector2 to )
	{
		float dx = from.x - to.x;
		float dy = from.y - to.y;
		float distance = 1 / Q_rsqrt ( dx * dx + dy * dy );
		return distance;
	}
	float Dot ( const Vector2 & other ) const
	{
		return x * other.x + y * other.x;
	}
	float Cross ( const Vector2 & other ) const
	{
		return x * y - y * x
	}
	float GetAngleBetween( Vector2 from , Vector2 to )
	{
		float dot = to.x * from.x + to.y * from.y;
		float cross = from.x * to.y - from.y * to.x; 
		float angle = atan2 ( cross , dot );
		return angle * ( 180.0f / 3.14159265f );
	}
	Vector2 Lerp ( Vector2 from , Vector2 to , float dt )
	{
		return from + ( to - from ) * dt; 
	}
	void operator!()
	{
		Normalize();
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
};