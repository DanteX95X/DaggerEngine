#ifndef VECTOR2_H
#define VECTOR2_H

struct Vector2
{
public:
	Vector2(double xInit = 0, double yInit = 0);

	Vector2& operator += (const Vector2& vector);
	Vector2& operator -= (const Vector2& vector);
	Vector2& operator = (const Vector2& vector);

	friend Vector2 operator - (const Vector2& vector);
	friend Vector2 operator - (const Vector2& first, const Vector2& second);
	friend Vector2 operator + (const Vector2& first, const Vector2& second);

	friend bool operator == (const Vector2& first, const Vector2& second);
	friend bool operator != (const Vector2& first, const Vector2& second);

	double x;
	double y;

};

#endif // VECTOR2_H
