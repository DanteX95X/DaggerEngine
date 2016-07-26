#include "scene.h"
#include <iostream>
#include "utilities/collisionDetection.h"

Scene::Scene(SDL_Renderer* rendererInit, std::string name)
	:renderer{rendererInit}, sceneName{name}
{
		CreateTextures();
		//CreateActors();
}

Scene::~Scene()
{
	for(std::pair<std::string, SDL_Texture*> pair : textures)
		SDL_DestroyTexture(pair.second);
}

void Scene::CreateTextures()
{
	std::ifstream spriteList("scenes/" + sceneName + "_sprites");
	std::cout << "scenes/" + sceneName + "_sprites\n\n";
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

//void Scene::CreateActors()
//{
//	std::ifstream actorsList("scenes/" + sceneName + "_actors");
//	std::string actorName;
//	double posX, posY, posW, posH;
//	bool isVisible;
//	while(actorsList >> actorName >> posX >> posY >> posW >> posH >> isVisible )
//	{
//		Actor newActor(*this, actorName, {posX, posY}, {posW, posH}, isVisible);
//		actors.push_back(newActor);
//	}
//}


void Scene::RenderScene()
{
	//std::cout << "Actors " << actors.size() << "\n";
	for(Actor& actor : actors)
		if(actor.GetIsVisible())
		{
			SDL_Rect destinationRectangle = { static_cast<int>(actor.GetPosition().x), static_cast<int>(actor.GetPosition().y), static_cast<int>(actor.GetSize().x), static_cast<int>(actor.GetSize().y)};
			SDL_RenderCopy(renderer, actor.GetTexture(), nullptr, &destinationRectangle);
		}
}

void Scene::HandleEvents(SDL_Event &event)
{
	for(Actor& actor : actors)
		actor.HandleEvents(event);
}

void Scene::Update()
{
	for(Actor& actor : actors)
		actor.Update();

	for(std::size_t firstIterator = 0; firstIterator < actors.size(); ++firstIterator)
		for(std::size_t secondIterator = firstIterator + 1; secondIterator < actors.size(); ++secondIterator)
			if(actors[firstIterator].GetIsCollidable() && actors[secondIterator].GetIsCollidable() && CollisionDetection::BoundingRectangle(actors[firstIterator], actors[secondIterator]))
			{
				actors[firstIterator].HandleCollision(actors[secondIterator]);
				actors[secondIterator].HandleCollision(actors[firstIterator]);
			}
}

void Scene::AddActor(Actor& actor) {actors.push_back(actor);}

SDL_Texture* Scene::GetTexture(std::string key) {return textures[key];}
