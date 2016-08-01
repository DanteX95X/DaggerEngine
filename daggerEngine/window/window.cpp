#include "window.h"
#include <assert.h>


Window::Window(unsigned int widthInit, unsigned int heightInit, std::string title)
	: width{widthInit}, height{heightInit}
{
	InitializeSDL();
	InitializeIMG();
	InitializeMixer();
	SetUpWindow(width, height, title);
}

Window::~Window()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}

void Window::InitializeSDL()
{
	assert(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != -1);
}

void Window::InitializeIMG()
{
	assert((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) == IMG_INIT_PNG);
}

void Window::InitializeMixer()
{
	assert(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) >= 0);
}

void Window::CreateWindow(unsigned int width, unsigned int height, std::string title, Uint32 flags)
{
	if(window != nullptr)
		SDL_DestroyWindow(window);
	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, flags);
	assert(window != nullptr);
}

void Window::CreateRenderer()
{
	if(renderer != nullptr)
		SDL_DestroyRenderer(renderer);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	assert(renderer != nullptr);
}

void Window::SetUpWindow(unsigned int width, unsigned int height, std::string title, Uint32 flags)
{
	CreateWindow(width, height, title, flags);
	CreateRenderer();
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	windowSurface = SDL_GetWindowSurface(window);
}


SDL_Renderer* Window::GetRenderer() { return renderer; }
unsigned int Window::GetWidth() { return width; }
unsigned int Window::GetHeight() { return height; }
SDL_Window* Window::GetWindow() { return window; }
