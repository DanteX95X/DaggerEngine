#include "clickable.h"
#include <iostream>

Clickable::Clickable(std::function<void()> functionInit)
	: function{functionInit}
{
}

void Clickable::UpdateComponent(Actor& actor, SDL_Event& event)
{
	if(event.type == SDL_MOUSEBUTTONDOWN)
	{
		int x,y;
		SDL_GetMouseState(&x, &y);
		SDL_Rect position = actor.GetPosition();

		if(x > position.x && x < position.x + position.w && y > position.y && y < position.y + position.h)
			function();
	}
}
