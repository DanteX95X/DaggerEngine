#include "actor.h"
#include <iostream>

Actor::Actor(Scene& parentScene, std::string name, SDL_Rect positionInit, bool isVisibleInit)
	:position{positionInit.x, positionInit.y, positionInit.w, positionInit.h}, actorName{name}, isVisible{isVisibleInit}
{
	texture = parentScene.GetTexture(actorName);
	assert(texture != nullptr);
}

SDL_Texture* Actor::GetTexture() {return texture;}

SDL_Rect& Actor::GetPosition() {return position;}
void Actor::SetPosition(SDL_Rect newPosition) {position = newPosition;}

bool Actor::GetIsVisible() {return isVisible;}

void Actor::HandleEvents(SDL_Event &event)
{
	for(Component* component : components)
		component->HandleEvents(*this, event);
}

void Actor::Update()
{
	for(Component* component : components)
		component->Update(*this);
}

void Actor::AddComponent(Component* component) {components.push_back(component);}
