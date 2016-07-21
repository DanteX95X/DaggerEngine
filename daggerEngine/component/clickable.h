#ifndef BUTTON_H
#define BUTTON_H

#include "component.h"
#include <functional>

class Clickable : public Component
{
public:
	Clickable(std::function<void()> functionInit);
	void HandleEvents(Actor& actor, SDL_Event& event);
	void UpdateComponent(Actor& actor);

private:
	std::function<void()> function;
};

#endif // BUTTON_H
