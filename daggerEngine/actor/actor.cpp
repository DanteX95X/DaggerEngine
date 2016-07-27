#include "actor.h"
#include <iostream>

Actor::Actor(Scene& parentScene, std::string name, Vector2 positionInit, Vector2 sizeInit, bool isVisibleInit, bool isCollidableInit)
	:position{positionInit.x, positionInit.y}, size{sizeInit.x, sizeInit.y}, actorName{name}, isVisible{isVisibleInit}, isCollidable{isCollidableInit}
{
	LoadTexture(parentScene);
	assert(texture != nullptr);
}

Actor::Actor(const Actor& actor)
	:texture{actor.texture}, position{actor.position}, size{actor.size}, actorName{actor.actorName}, isVisible{actor.isVisible}, isCollidable{actor.isCollidable}
{
	for(Component* component : actor.components)
		components.push_back(component->Clone());
}

Actor::~Actor()
{
	for(std::size_t i = 0; i < components.size(); ++i)
		delete components[i];
}

void Actor::LoadTexture(Scene& currentScene)
{
	texture = currentScene.GetTexture(actorName);
}

SDL_Texture* Actor::GetTexture() { return texture; }

Vector2 Actor::GetPosition() { return position; }
Vector2 Actor::GetSize() { return size; }
void Actor::SetPosition(Vector2 newPosition) { position = newPosition; }

bool Actor::GetIsVisible() { return isVisible; }
void Actor::SetIsVisible(bool isVisible) { this->isVisible = isVisible; }
bool Actor::GetIsCollidable() { return isCollidable; }
void Actor::SetIsCollidable(bool isCollidable) { this->isCollidable = isCollidable; }

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

void Actor::HandleCollision(Actor& collider)
{
	for(Component*& Component : components)
		Component->HandleCollision(collider);
}

void Actor::AddComponent(Component* component) {components.push_back(component);}
