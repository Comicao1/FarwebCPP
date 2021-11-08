#include "SDL.h"

#define NORTH 1
#define WEST 2
#define SOUTH 3
#define EAST 4

#define SPEED 128 / 64
#define FPS 60
#define frameDelay 1000/FPS



class _game {
public:
	_game();
	~_game();
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running() { return isRunning; }
	static SDL_Renderer *renderer;
private:
	bool isRunning;
	SDL_Window *window;
};