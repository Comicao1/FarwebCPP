#include "TextureManager.h"
#include "Atom.h"
#include <iostream>
#include "Map.h"
#include "ECS/Components.h"

Map* map;
Manager manager;

auto& player(manager.addEntity());

SDL_Renderer* _game::renderer = nullptr;

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
	map = new Map();

	player.addComponent<TransformComponent>();
	player.addComponent<SpriteComponent>("assets/player.png");
}

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

	default:
		break;
	}


}

void _game::update() {
	manager.Update();
	manager.Refresh();
}

void _game::render() {
	SDL_RenderClear(renderer);
	map->DrawMap();
	manager.Draw();
	SDL_RenderPresent(renderer);
}

void _game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Destroyed." << std::endl;
}