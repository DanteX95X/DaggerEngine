#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "scene/scene.h"

class Scene;

class Window
{
public:
	Window(unsigned int widthInit = 640, unsigned int heightInit = 480, std::string title = "");
	~Window();

	void SetUpWindow(unsigned int width, unsigned int height, std::string title, Uint32 flags = SDL_WINDOW_SHOWN);

	SDL_Renderer* GetRenderer();

	unsigned int GetWidth();
	unsigned int GetHeight();

private:
	unsigned int width;
	unsigned int height;

	SDL_Window* window;
	SDL_Surface* windowSurface;
	SDL_Renderer* renderer;

	Scene* currentScene;

	bool InitializeSDL();
	bool InitializeIMG();
	bool CreateWindow(unsigned int width, unsigned int height, std::string title, Uint32 flags);
	bool CreateRenderer();
};

#endif // WINDOW_H
