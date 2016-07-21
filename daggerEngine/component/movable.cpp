#include "movable.h"
#include <iostream>
#include "timer/timer.h"

Movable::Movable(SDL_Point velocityInit)
	: velocity{velocityInit.x, velocityInit.y}
{

}

void Movable::HandleEvents(Actor &actor, SDL_Event &event)
{
	(void)actor; (void)event;
}

void Movable::Update(Actor &actor)
{
	Vector2 currentPosition = actor.GetPosition();
	currentPosition.x += velocity.x * Timer::GetDeltaTime();
	currentPosition.y += velocity.y * Timer::GetDeltaTime();
	actor.SetPosition(currentPosition);
}
