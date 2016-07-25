#ifndef COMPONENT_H
#define COMPONENT_H

#include "actor/actor.h"
class Actor;

class Component
{
public:
	virtual ~Component() {};

	virtual void HandleEvents(Actor& actor, SDL_Event& event) { (void)actor; (void)event; }
	virtual void Update(Actor& actor) { (void)actor; }
	virtual Component* Clone() = 0;
};

#endif // COMPONENT_H
