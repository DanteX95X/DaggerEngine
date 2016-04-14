#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <SDL2/SDL.h>
#include "scene/scene.h"

class Scene;

class Window
{
public:
	Window(unsigned int widthInit = 640, unsigned int heightInit = 480, std::string title = "");
	~Window();

	SDL_Renderer* GetRenderer();
private:
	unsigned int width;
	unsigned int height;

	SDL_Window* window;
	SDL_Surface* windowSurface;
	SDL_Renderer* renderer;

	Scene* currentScene;

	bool InitializeSDL();
	bool CreateWindow(std::string title);
	bool CreateRenderer();
};

#endif // WINDOW_H
