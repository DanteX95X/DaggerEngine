#include "movable.h"
#include <iostream>

Movable::Movable(SDL_Point velocityInit)
	: velocity{velocityInit.x, velocityInit.y}
{

}

void Movable::HandleEvents(Actor &actor, SDL_Event &event)
{
}

void Movable::UpdateComponent(Actor &actor)
{
	SDL_Rect currentPosition = actor.GetPosition();
	currentPosition.x += velocity.x;
	currentPosition.y += velocity.y;
	std::cout << actor.GetPosition().x << " " << actor.GetPosition().y << '\n';
	actor.SetPosition(currentPosition);
	std::cout << actor.GetPosition().x << " " << actor.GetPosition().y << '\n';
}
