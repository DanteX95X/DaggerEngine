#ifndef ACTOR_H
#define ACTOR_H

#include <SDL2/SDL.h>
#include <string>
#include "scene/scene.h"
#include "component/component.h"
#include "utilities/vector2.h"

class Scene;
class Component;

class Actor
{
public:
	Actor(Scene& parentScene, std::string name, Vector2 positionInit, Vector2 sizeInit, bool isVisibleInit);
	Actor(const Actor& actor);
	~Actor();

	void HandleEvents(SDL_Event& event);
	void Update();

	void AddComponent(Component* component);

	SDL_Texture* GetTexture();

	Vector2& GetPosition();
	Vector2& GetSize();

	void SetPosition(Vector2 newPosition);

	bool GetIsVisible();
private:
	SDL_Texture* texture;
	//SDL_Rect position;
	Vector2 position;
	Vector2 size;

	std::vector<Component*> components;

	std::string actorName;
	bool isVisible;
};

#endif // ACTOR_H
