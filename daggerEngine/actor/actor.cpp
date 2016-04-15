#include "actor.h"

Actor::Actor(Scene& parentScene, std::string name, SDL_Rect positionInit)
	:position{positionInit.x, positionInit.y, positionInit.w, positionInit.h}, actorName{name}
{
	texture = parentScene.GetTexture(actorName);
	assert(texture != nullptr);
}

SDL_Texture* Actor::GetTexture()
{
	return texture;
}

SDL_Rect& Actor::GetPosition()
{
	return position;
}
