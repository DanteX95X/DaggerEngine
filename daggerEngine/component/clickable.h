#ifndef BUTTON_H
#define BUTTON_H

#include "component.h"
#include <functional>
#include "audio/sound_player.h"

class Clickable : public Component
{
public:
	Clickable(std::function<void()> functionInit);
	void HandleEvents(Actor& actor, SDL_Event& event) override;
	Component* Clone() override;

private:
	std::function<void()> function;
	SoundPlayer player;
};

#endif // BUTTON_H
