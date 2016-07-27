#include "window.h"
#include <assert.h>


Window::Window(unsigned int widthInit, unsigned int heightInit, std::string title)
	: width{widthInit}, height{heightInit}
{
	assert(InitializeSDL());
	assert(InitializeIMG());
//	assert(CreateWindow(title));
//	assert(CreateRenderer());
//	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
//	windowSurface = SDL_GetWindowSurface(window);
	SetUpWindow(width, height, title);
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

bool Window::CreateWindow(unsigned int width, unsigned int height, std::string title, Uint32 flags)
{
	if(window != nullptr)
		SDL_DestroyWindow(window);
	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, flags);
	return window != nullptr;
}

bool Window::CreateRenderer()
{
	if(renderer != nullptr)
		SDL_DestroyRenderer(renderer);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	return renderer != nullptr;
}

void Window::SetUpWindow(unsigned int width, unsigned int height, std::string title, Uint32 flags)
{
	CreateWindow(width, height, title, flags);
	CreateRenderer();
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	windowSurface = SDL_GetWindowSurface(window);
}


SDL_Renderer* Window::GetRenderer() {return renderer;}
