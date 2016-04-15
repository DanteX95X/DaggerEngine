#include "window/window.h"
#include <iostream>

using namespace std;

int main()
{
	bool isDone = false;
	SDL_Event event;
	Window temp;
	std::vector<Scene> ufo;
	Scene scene(temp.GetRenderer(), "scene");
	ufo.push_back(scene);

	ufo[0].RenderScene();
	//SDL_RenderCopy(temp.GetRenderer(), ufo[0].actors[0].GetTexture(), nullptr, nullptr);
	//SDL_RenderCopy(temp.GetRenderer(), ufo[0].GetTexture("crate"), nullptr, nullptr);
	SDL_RenderPresent(temp.GetRenderer());

	while(!isDone)
	{
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
				isDone = true;
		}
	}
}

