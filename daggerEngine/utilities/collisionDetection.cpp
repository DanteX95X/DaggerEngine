#include "collisionDetection.h"

bool CollisionDetection::BoundingRectangle(Actor& first, Actor& second)
{
	return
		first.GetPosition().x < second.GetPosition().x + second.GetSize().x
		&& first.GetPosition().x + first.GetSize().x > second.GetPosition().x
		&& first.GetPosition().y < second.GetPosition().y + second.GetSize().y
		&& first.GetPosition().y + first.GetSize().y > second.GetPosition().y;
}
