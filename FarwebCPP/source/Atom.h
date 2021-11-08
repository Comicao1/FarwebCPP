#pragma once
#include "game.h"

class Atom {
public:
	Atom(const char* textureSheet, int size_x, int size_y, int x, int y);
	~Atom();

	int dir;
	int cnt;
	bool isMoving = false;
	int pixel_x, pixel_y;
	int sizeY, sizeX = 32;
	int x, y, z;

	void update();
	void render();
	void handleEvents();
private:
	SDL_Texture* atomTexture;
	SDL_Rect srcRect, destRect;

};