#include "collisionDetection.h"

bool CollisionDetection::BoundingRectangle(Actor& first, Actor& second)
{
	Vector2 firstPosition = first.GetPosition();
	Vector2 firstSize = first.GetSize();
	Vector2 secondPosition = second.GetPosition();
	Vector2 secondSize = second.GetSize();

	return
		firstPosition.x < secondPosition.x + secondSize.x
		&& firstPosition.x + firstSize.x > secondPosition.x
		&& firstPosition.y < secondPosition.y + secondSize.y
		&& firstPosition.y + firstSize.y > secondPosition.y;
}
