#include "window/window.h"
#include <iostream>
#include "component/clickable.h"
#include "component/movable.h"
#include "timer/timer.h"

using namespace std;

int main()
{
	bool isDone = false;
	SDL_Event event;
	Window temp;
	std::vector<Scene> ufo;
	Scene scene(temp, "scene", {100,0});
	ufo.push_back(scene);

	Actor newActor(ufo[0], "crate", {0, 0}, {100, 100}, true, true);
	newActor.AddComponent(new Clickable([]{std::cout << "button clicked\n";}));
	newActor.AddComponent(new Movable({100, 0}));
	ufo[0].AddActor(newActor);

	newActor = Actor(ufo[0], "crate", {540, 0}, {100, 100}, true, true);
	newActor.AddComponent(new Movable({-100, 0}));
	//for(int i=0; i < 100; ++i)
	ufo[0].AddActor(newActor);

	while(!isDone)
	{
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
				isDone = true;
			if(event.type == SDL_KEYDOWN)
				if(event.key.keysym.sym == SDLK_RETURN)
				{
					temp.SetUpWindow(800, 600, "new window");
					for(Scene& scene : ufo)
						scene.ReloadScene(temp.GetRenderer());
				}
			ufo[0].HandleEvents(event);
		}
		Timer::Instance().Update();

		ufo[0].Update();
		SDL_RenderClear(temp.GetRenderer());

		ufo[0].RenderScene();

		SDL_RenderPresent(temp.GetRenderer());
	}
}

