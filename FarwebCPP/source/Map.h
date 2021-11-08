#pragma once
#include "SDL.h"

class Map {
public:
	Map();
	~Map();

	void LoadMap(int[20][20]);
	void DrawMap();

private:
	SDL_Rect src, dest;
	SDL_Texture* graystone;
	SDL_Texture* bluestone;
	SDL_Texture* merch;
	SDL_Texture* dark;
	SDL_Texture* dirt;
	SDL_Texture* dirt2;
	SDL_Texture* cerb;
	SDL_Texture* plaza;

	int map[20][20];
};