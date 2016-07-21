#include "window/window.h"
#include <iostream>
#include "component/clickable.h"
#include "component/movable.h"

using namespace std;

int main()
{
	bool isDone = false;
	SDL_Event event;
	Window temp;
	std::vector<Scene> ufo;
	Scene scene(temp.GetRenderer(), "scene");
	ufo.push_back(scene);

	Actor newActor(ufo[0], "crate", {0, 0, 100, 100}, true);
	newActor.AddComponent(new Clickable([]{std::cout << "button clicked\n";}));
	newActor.AddComponent(new Movable({1,1}));
	ufo[0].AddActor(newActor);


	while(!isDone)
	{
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
				isDone = true;
			ufo[0].HandleEvents(event);
		}
		ufo[0].UpdateScene();
		SDL_RenderClear(temp.GetRenderer());

		ufo[0].RenderScene();

		SDL_RenderPresent(temp.GetRenderer());
	}
}

