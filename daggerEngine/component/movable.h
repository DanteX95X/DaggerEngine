#ifndef MOVABLE_H
#define MOVABLE_H

#include <SDL2/SDL.h>
#include "movable.h"
#include "component.h"

class Movable : public Component
{
public:
	Movable(SDL_Point velocityInit);
	void HandleEvents(Actor &actor, SDL_Event &event);
	void UpdateComponent(Actor& actor);

private:
	SDL_Point velocity;
};

#endif // MOVABLE_H
