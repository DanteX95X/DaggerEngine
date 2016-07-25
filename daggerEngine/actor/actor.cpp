#include "actor.h"
#include <iostream>

Actor::Actor(Scene& parentScene, std::string name, Vector2 positionInit, Vector2 sizeInit, bool isVisibleInit)
	:position{positionInit.x, positionInit.y}, size{sizeInit.x, sizeInit.y}, actorName{name}, isVisible{isVisibleInit}
{
	texture = parentScene.GetTexture(actorName);
	assert(texture != nullptr);
}

Actor::Actor(const Actor& actor)
	:texture{actor.texture}, position{actor.position}, size{actor.size}, actorName{actor.actorName}, isVisible{actor.isVisible}
{
	for(Component* component : actor.components)
		components.push_back(component->Clone());
}

Actor::~Actor()
{
	for(std::size_t i = 0; i < components.size(); ++i)
		delete components[i];
}

SDL_Texture* Actor::GetTexture() { return texture; }

Vector2& Actor::GetPosition() { return position; }
Vector2& Actor::GetSize() { return size; }
void Actor::SetPosition(Vector2 newPosition) { position = newPosition; }

bool Actor::GetIsVisible() { return isVisible; }

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
