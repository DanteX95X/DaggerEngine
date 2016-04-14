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

class Scene
{
public:
	Scene(SDL_Renderer* rendererInit, std::string name);
	~Scene();

	SDL_Texture* GetTexture(std::string key);

private:
	SDL_Renderer* renderer;

	std::string sceneName;

	std::vector<Actor> actors;
	std::unordered_map<std::string, SDL_Texture*> textures;

	void LoadTexture(std::string key, std::string imagePath);
};

#endif // SCENE_H
