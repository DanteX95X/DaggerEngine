#include "window.h"
#include <assert.h>


Window::Window(unsigned int widthInit, unsigned int heightInit, std::string title)
	: width{widthInit}, height{heightInit}
{
	assert(InitializeSDL());
	assert(InitializeIMG());
	assert(CreateWindow(title));
	assert(CreateRenderer());
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	windowSurface = SDL_GetWindowSurface(window);
}

Window::~Window()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

bool Window::InitializeSDL()
{
	return (SDL_Init(SDL_INIT_VIDEO) != -1);
}

bool Window::InitializeIMG()
{
	return ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) == IMG_INIT_PNG);
}

bool Window::CreateWindow(std::string title)
{
	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	return window != nullptr;
}

bool Window::CreateRenderer()
{
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	return renderer != nullptr;
}

SDL_Renderer* Window::GetRenderer() {return renderer;}
