#include "vector2.h"

Vector2::Vector2(double xInit, double yInit)
	: x{xInit}, y{yInit}
{

}

Vector2& Vector2::operator += (const Vector2& vector)
{
	x += vector.x;
	y += vector.y;
	return *this;
}

Vector2& Vector2::operator -= (const Vector2& vector)
{
	return *this += -vector;
}

Vector2& Vector2::operator = (const Vector2& vector)
{
	x = vector.x;
	y = vector.y;
	return *this;
}

Vector2 operator - (const Vector2& vector)
{
	return Vector2(-vector.x, -vector.y);
}

Vector2 operator + (const Vector2& first, const Vector2& second)
{
	return Vector2(first.x + second.x, first.y + second.y);
}

Vector2 operator - (const Vector2& first, const Vector2& second)
{
	return Vector2(first.x - second.x, first.y - second.y);
}


bool operator == (const Vector2& first, const Vector2& second)
{
	return first.x == second.x && first.y == second.y;
}

bool operator != (const Vector2& first, const Vector2& second)
{
	return !(first == second);
}
