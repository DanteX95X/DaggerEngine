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

class Actor;

class Scene
{
public:
	Scene(SDL_Renderer* rendererInit, std::string name);
	~Scene();

	void HandleEvents(SDL_Event& event);
	void Update();
	void RenderScene();

	void AddActor(Actor& actor);

	SDL_Texture* GetTexture(std::string key);

private:
	SDL_Renderer* renderer;

	std::string sceneName;

	std::vector<Actor> actors;
	std::unordered_map<std::string, SDL_Texture*> textures;

	void CreateTextures();
	void CreateActors();
};

#endif // SCENE_H
