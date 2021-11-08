#include "game.h"

SDL_Texture* playerTex;
SDL_Rect srcR, destR;

_game::_game(){}
_game::~_game(){}

void _game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems Initialized." << std::endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);
		if (window) {
			std::cout << "Window has been created." << std::endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			std::cout << "Renderer has been created." << std::endl;
		}
		isRunning = true;
	}
	else {
		isRunning = false;
		std::cout << "Failed to initialize" << std::endl;
	}
	playerTex = TextureManager::LoadTexture("assets/player.png", renderer);
;}

void _game::handleEvents(){
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_KEYUP:
		if (event.key.keysym.sym == SDLK_ESCAPE) {
			isRunning = false;	
		}
		isMoving = false;
		dir = NULL;
		std::cout << "Subiu" << std::endl;
		break;
	case SDL_KEYDOWN:
		if (event.key.keysym.sym == SDLK_w) {
			dir = NORTH;
		}
		if (event.key.keysym.sym == SDLK_a) {
			dir = WEST;
		}
		if (event.key.keysym.sym == SDLK_s) {
			dir = SOUTH;
		}
		if (event.key.keysym.sym == SDLK_d) {
			dir = EAST;
		}
		isMoving = true;
		break;
	default:
		break;
	}


}

void _game::update() {
	destR.h = 128;
	destR.w = 128;
	std::cout << dir << " " << isMoving << std::endl;
	if (isMoving && dir) {
		if (dir == NORTH) {
			destR.y -= SPEED;
		}
		else if (dir == WEST) {
			destR.x -= SPEED;
		}
		else if (dir == SOUTH) {
			destR.y += SPEED;
		}
		else if (dir == EAST) {
			destR.x += SPEED;
		}
	}
}

void _game::render() {
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, playerTex, NULL, &destR);
	SDL_RenderPresent(renderer);
}

void _game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Destroyed." << std::endl;
}