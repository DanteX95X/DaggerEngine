#ifndef COMPONENT_H
#define COMPONENT_H

#include "actor/actor.h"
class Actor;

class Component
{
public:
	virtual void UpdateComponent(Actor& actor, SDL_Event& event) = 0;
};

#endif // COMPONENT_H
