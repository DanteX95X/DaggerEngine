#include "actor.h"

Actor::Actor(Scene& parentScene, std::string name, SDL_Rect positionInit, bool isVisibleInit)
	:position{positionInit.x, positionInit.y, positionInit.w, positionInit.h}, actorName{name}, isVisible{isVisibleInit}
{
	texture = parentScene.GetTexture(actorName);
	assert(texture != nullptr);
}

SDL_Texture* Actor::GetTexture() {return texture;}

SDL_Rect& Actor::GetPosition() {return position;}

bool Actor::GetIsVisible() {return isVisible;}
