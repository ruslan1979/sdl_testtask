#include "Client.h"

Client & Client::getInstance()
{
	// TODO: вставьте здесь оператор return
	static Client c;
	return c;
}

void Client::run()
{

	// initial check
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		throw runtime_error(string("SDL_Init Error: ") + SDL_GetError());
	
	SDL_Window *win = SDL_CreateWindow("I am an AWEMer!!!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	if (win == nullptr)
		throw runtime_error(string("SDL_CreateWindow Error: ") + SDL_GetError());
	
	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr)
		throw runtime_error(string("SDL_CreateRenderer Error: ") + SDL_GetError());
	
	// closing the program
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);

	SDL_Quit();

}
