#include "SDL.h"

int main(int argc, char* argv[]) {
	SDL_Window* window = SDL_CreateWindow(
		"PLOT FOUR", 
		SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED, 
		500, 500, 
		SDL_WINDOW_OPENGL);
	SDL_Delay(16000);
	return 0;
}
