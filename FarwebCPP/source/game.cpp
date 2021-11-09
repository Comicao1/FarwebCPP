#include "TextureManager.h"
#include "Atom.h"
#include <iostream>
#include "Map.h"
#include "ECS/Components.h"
#include "Vector2D.h"
#include <vector>
#include "Collision.h"

Map* map;
Manager manager;

auto& player(manager.addEntity());


SDL_Renderer* _game::renderer = nullptr;
SDL_Event _game::event;

SDL_Rect _game::camera = {0,0,800,640};

_game::_game() {}
_game::~_game() {}

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

	map = new Map("assets/prestamais.png", 2 ,32);

	map->LoadMap("assets/Mapa1.map", 25 , 20 );

	player.addComponent<TransformComponent>(800.0f, 640.0f, 32 , 32, 4);
	player.addComponent<SpriteComponent>("assets/paide.png", true);
	player.addComponent<KeyboardController>();
	player.addComponent<ColliderComponent>("player");
	player.addGroup(groupPlayers);
}

auto& tiles(manager.getGroup(_game::groupMap));
auto& players(manager.getGroup(_game::groupPlayers));
auto& colliders(manager.getGroup(_game::groupColliders));

void _game::handleEvents() {
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void _game::update() {

	SDL_Rect playerCol = player.getComponent<ColliderComponent>().collider;
	Vector2D playerPos = player.getComponent<TransformComponent>().position;


	manager.Update();
	manager.Refresh();

	for (auto& c : colliders) {
		SDL_Rect cCol = c->getComponent<ColliderComponent>().collider;
		if (Collision::AABB(cCol, playerCol)) {
			player.getComponent<TransformComponent>().position = playerPos;
		}
	}

	camera.x = player.getComponent<TransformComponent>().position.x - 320;
	camera.y = player.getComponent<TransformComponent>().position.y - 240;
	
	if (camera.x < 0) {
		camera.x = 0;
	}if (camera.y < 0) {
		camera.y = 0;
	}if (camera.x > camera.w) {
		camera.x = camera.w;
	}if (camera.y > camera.h) {
		camera.y = camera.h;
	}

}

void _game::render() {
	SDL_RenderClear(renderer);
	for (auto& t : tiles) {
		t->draw();
	}
	for (auto& c : colliders) {
		c->draw();
	}
	for (auto& t : players) {
		t->draw();
	}
	SDL_RenderPresent(renderer);
}

void _game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Destroyed." << std::endl;
}