#include "Atom.h"
#include "SDL.h"
#include "TextureManager.h"
#include <iostream>

Atom::Atom(const char* textureSheet, int size_x, int size_y, int x, int y) {
	atomTexture = TextureManager::LoadTexture(textureSheet);
	pixel_x = x;
	pixel_y = y;
	sizeX = size_x;
	sizeY = size_y;
}

void Atom::update() {

	srcRect.h = sizeY;
	srcRect.w = sizeX;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = pixel_x;
	destRect.y = pixel_y;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;
	std::cout << dir << " " << isMoving << std::endl;
	if (isMoving && dir) {
		if (dir == NORTH) {
			pixel_y -= SPEED;
		}
		else if (dir == WEST) {
			pixel_x -= SPEED;
		}
		else if (dir == SOUTH) {
			pixel_y += SPEED;
		}
		else if (dir == EAST) {
			pixel_x += SPEED;
		}
	}

}

void Atom::handleEvents(){
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_KEYUP:
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

void Atom::render() {
	SDL_RenderCopy(_game::renderer, atomTexture, &srcRect, &destRect);
}