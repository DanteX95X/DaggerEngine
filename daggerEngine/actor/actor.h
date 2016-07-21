#ifndef ACTOR_H
#define ACTOR_H

#include <SDL2/SDL.h>
#include <string>
#include "scene/scene.h"
#include "component/component.h"

class Scene;
class Component;

class Actor
{
public:
	Actor(Scene& parentScene, std::string name, SDL_Rect positionInit, bool isVisibleInit);

	void HandleEvents(SDL_Event& event);
	void Update();

	void AddComponent(Component* component);

	SDL_Texture* GetTexture();

	SDL_Rect& GetPosition();
	void SetPosition(SDL_Rect newPosition);

	bool GetIsVisible();
private:
	SDL_Texture* texture;
	SDL_Rect position;

	std::vector<Component*> components;

	std::string actorName;
	bool isVisible;
};

#endif // ACTOR_H
