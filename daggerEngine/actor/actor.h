#ifndef ACTOR_H
#define ACTOR_H

#include <SDL2/SDL.h>
#include <string>
#include "scene/scene.h"

class Scene;

class Actor
{
public:
	Actor(Scene& parentScene, std::string name, SDL_Rect positionInit, bool isVisibleInit);

	SDL_Texture* GetTexture();
	SDL_Rect& GetPosition();
	bool GetIsVisible();
private:
	SDL_Texture* texture;
	SDL_Rect position;

	std::string actorName;
	bool isVisible;
};

#endif // ACTOR_H
