#include "Map.h"
#include "TextureManager.h"

int lvl1[20][20] = {
	{1,1,2,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{1,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,1,0,1,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

Map::Map() {
	graystone = TextureManager::LoadTexture("assets/graystone.png");
	bluestone = TextureManager::LoadTexture("assets/bluestone.png");
	merch = TextureManager::LoadTexture("assets/merch.png");
	dark = TextureManager::LoadTexture("assets/dark.png");
	dirt = TextureManager::LoadTexture("assets/dirt.png");
	dirt2 = TextureManager::LoadTexture("assets/dirt2.png");
	cerb = TextureManager::LoadTexture("assets/cerb.png");
	plaza = TextureManager::LoadTexture("assets/plaza.png");

	LoadMap(lvl1);
	src.x = src.y = 0;
	src.w = dest.w = 64;
	src.h = dest.h = 64;

	dest.x = dest.y = 0;
}

void Map::LoadMap(int arr[20][20]) {
	for (int row = 0; row < 20; row++) {
		for (int column = 0; column < 20; column++) {
			map[row][column] = arr[row][column];
		}
	}
}

void Map::DrawMap() {
	int type = 0;
	for (int row = 0; row < 20; row++) {
		for (int column = 0; column < 20; column++) {
			type = map[row][column];
			dest.x = 64 * column;
			dest.y = 64 * row;
			switch (type) {
			case 0:
				TextureManager::Draw(dirt, src, dest);
				break;
			case 1:
				TextureManager::Draw(cerb, src, dest);
				break;
			case 2:
				TextureManager::Draw(plaza, src, dest);
				break;
			default:
				break;
			}
		}
	}
}