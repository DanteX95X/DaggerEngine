#ifndef BUTTON_H
#define BUTTON_H

#include "component.h"
#include <functional>

class Clickable : public Component
{
public:
	Clickable(std::function<void()> functionInit);
	void UpdateComponent(Actor& actor, SDL_Event& event);

private:
	std::function<void()> function;
};

#endif // BUTTON_H
