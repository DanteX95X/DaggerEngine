#ifndef COMPONENT_H
#define COMPONENT_H

#include "actor/actor.h"
class Actor;

class Component
{
public:
	virtual void HandleEvents(Actor& actor, SDL_Event& event) = 0;
	virtual void Update(Actor& actor) = 0;
};

#endif // COMPONENT_H
