#ifndef COMPONENT_H
#define COMPONENT_H

#include "actor/actor.h"
class Actor;


enum class ComponentType
{
	CLICKABLE,
	MOVABLE,
};


class Component
{
public:
	virtual ~Component() {};

	virtual void HandleEvents(Actor& actor, SDL_Event& event) { (void)actor; (void)event; }
	virtual void Update(Actor& actor) { (void)actor; }
	virtual void HandleCollision(Actor& collider) { (void)collider; }
	virtual Component* Clone() = 0;

	ComponentType GetType() { return type; }

protected:
	ComponentType type;
};

#endif // COMPONENT_H
