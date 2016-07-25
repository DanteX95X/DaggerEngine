#include "clickable.h"
#include <iostream>

Clickable::Clickable(std::function<void()> functionInit)
	: function{functionInit}
{
}

Component* Clickable::Clone()
{
	return new Clickable(*this);
}

void Clickable::HandleEvents(Actor& actor, SDL_Event& event)
{
	if(event.type == SDL_MOUSEBUTTONDOWN)
	{
		int x,y;
		SDL_GetMouseState(&x, &y);
		Vector2 position = actor.GetPosition();
		Vector2 size = actor.GetSize();

		if(x > position.x && x < position.x + size.x && y > position.y && y < position.y + size.y)
			function();
	}
}
