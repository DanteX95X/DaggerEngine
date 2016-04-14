#include "window/window.h"
#include <iostream>

using namespace std;

int main()
{
	Window temp;
	Scene scene(temp.GetRenderer(), "scene");
	SDL_RenderCopy(temp.GetRenderer(), scene.GetTexture("hello"), nullptr, nullptr);
	SDL_RenderCopy(temp.GetRenderer(), scene.GetTexture("crate"), nullptr, nullptr);
	SDL_RenderPresent(temp.GetRenderer());
	SDL_Delay(5000);
}

