#include "scene.h"
#include <iostream>

Scene::Scene(SDL_Renderer* rendererInit, std::string name)
	:renderer{rendererInit}, sceneName{name}
{
	std::ifstream assetDatabase("scenes/" + name);
	std::string key, value;
	while(assetDatabase >> key && assetDatabase >> value)
		LoadTexture(key, value);
}

Scene::~Scene()
{
	for(std::pair<std::string, SDL_Texture*> pair : textures)
		SDL_DestroyTexture(pair.second);
}

void Scene::LoadTexture(std::string key, std::string imagePath)
{
	std::cout << "Loading sprite\n \tkey: " << key << "\n \tpath: " << imagePath << "\n";
	SDL_Surface* surface;
	surface = SDL_LoadBMP(imagePath.c_str());
	assert(surface != nullptr);

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	assert(texture != nullptr);
	SDL_FreeSurface(surface);

	textures[key] = texture;
}

SDL_Texture* Scene::GetTexture(std::string key)
{
	return textures[key];
}
