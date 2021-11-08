#include "game.h"

_game *game = nullptr;

int main(int argc, char * argv[]) {
	game = new _game();
	game->init("Farweb - Theater of Pain", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
	Uint32 frameStart;
	Uint32 frameTime;


	while (game->running()) {
		frameStart = SDL_GetTicks();
		game->handleEvents();
		game->render();
		game->update();
		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}

	return 0;
}