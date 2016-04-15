#ifndef ACTOR_H
#define ACTOR_H

#include <SDL2/SDL.h>
#include <string>
#include "scene/scene.h"

class Scene;

class Actor
{
public:
	Actor(Scene& parentScene, std::string name, SDL_Rect positionInit);

	SDL_Texture* GetTexture();
	SDL_Rect& GetPosition();
private:
	SDL_Texture* texture;
	SDL_Rect position;

	std::string actorName;
};

#endif // ACTOR_H
