#include "SDL.h"

int main(int argc, char* argv[]) {
	SDL_Window* window = SDL_CreateWindow(
		"PLOT FOUR", 
		SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED, 
		500, 500, 
		SDL_WINDOW_SHOWN);

	SDL_Renderer* render = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
	SDL_RenderClear(render);
	SDL_RenderPresent(render);
	SDL_Delay(16000);
	return 0;
}
