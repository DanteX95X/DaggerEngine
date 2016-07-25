#include "movable.h"
#include <iostream>
#include "timer/timer.h"

Movable::Movable(Vector2 velocityInit)
	: velocity{velocityInit.x, velocityInit.y}
{

}

Component* Movable::Clone()
{
	return new Movable(*this);
}

void Movable::HandleEvents(Actor &actor, SDL_Event &event)
{
	(void)actor; (void)event;
}

void Movable::Update(Actor &actor)
{
	Vector2 currentPosition = actor.GetPosition();
	currentPosition += velocity * Timer::GetDeltaTime();
	actor.SetPosition(currentPosition);
}
