#include "scene.h"
#include <iostream>

Scene::Scene(SDL_Renderer* rendererInit, std::string name)
	:renderer{rendererInit}, sceneName{name}
{
		CreateTextures();
		CreateActors();
}

Scene::~Scene()
{
	for(std::pair<std::string, SDL_Texture*> pair : textures)
		SDL_DestroyTexture(pair.second);
}

void Scene::CreateTextures()
{
	std::ifstream spriteList("scenes/" + sceneName + "_sprites");
	std::string key, imagePath;
	while(spriteList >> key && spriteList >> imagePath)
	{
		std::cout << "Loading sprite\n \tkey: " << key << "\n \tpath: " << imagePath << "\n";
		SDL_Surface* surface;
		surface = IMG_Load(imagePath.c_str());
		assert(surface != nullptr);

		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
		assert(texture != nullptr);
		SDL_FreeSurface(surface);

		textures[key] = texture;
	}
}

void Scene::CreateActors()
{
	std::ifstream actorsList("scenes/" + sceneName + "_actors");
	std::string actorName;
	int posX, posY, posW, posH;
	while(actorsList >> actorName >> posX >> posY >> posW >> posH)
	{
		Actor newActor(*this, actorName, {posX, posY, posW, posH});
		actors.push_back(newActor);
	}

}


void Scene::RenderScene()
{
	std::cout << "Actors " << actors.size() << "\n";
	for(Actor actor : actors)
		SDL_RenderCopy(renderer, actor.GetTexture(), nullptr, &actor.GetPosition());
}

SDL_Texture* Scene::GetTexture(std::string key)
{
	return textures[key];
}
