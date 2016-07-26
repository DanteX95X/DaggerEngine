#ifndef MOVABLE_H
#define MOVABLE_H

#include <SDL2/SDL.h>
#include "movable.h"
#include "component.h"

class Movable : public Component
{
public:
	Movable(Vector2 velocityInit);
	void Update(Actor& actor) override;
	void HandleCollision(Actor& collider) override;
	Component* Clone() override;

private:
	Vector2 velocity;
};

#endif // MOVABLE_H
