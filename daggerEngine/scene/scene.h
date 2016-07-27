#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "actor/actor.h"
#include "window/window.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <unordered_map>
#include <assert.h>
#include <fstream>
#include "utilities/vector2.h"

class Window;
class Actor;

class Scene
{
public:
	Scene(Window& window, std::string name, Vector2 cameraPositionInit = {0,0});
	~Scene();

	void HandleEvents(SDL_Event& event);
	void Update();
	void RenderScene();

	void AddActor(Actor& actor);

	void ReloadScene(SDL_Renderer* renderer);
	SDL_Texture* GetTexture(std::string key);

private:
	SDL_Renderer* renderer;

	std::string sceneName;

	std::vector<Actor> actors;
	std::unordered_map<std::string, SDL_Texture*> textures;

	Vector2	cameraPosition;
	Vector2 cameraSize;

	void CreateTextures();
	void DestroyTextures();
	void CreateActors();
};

#endif // SCENE_H
