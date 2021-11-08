#pragma once
#include "Components.h"

class KeyboardController : public Component {
public:
	TransformComponent *transform;
	void init() override {
		transform = &entity->getComponent<TransformComponent>();
	}
	void update() override {
		if (_game::event.type == SDL_KEYDOWN) {
			switch (_game::event.key.keysym.sym) {
			case SDLK_w:
				transform->velocity.y = -1;
				break;
			case SDLK_a:
				transform->velocity.x = -1;
				break;
			case SDLK_d:
				transform->velocity.x = 1;
				break;
			case SDLK_s:
				transform->velocity.y = 1;
				break;
			default:
				break;
			}
		}
		if (_game::event.type == SDL_KEYUP) {
			switch (_game::event.key.keysym.sym) {
			case SDLK_w:
				transform->velocity.y = 0;
				break;
			case SDLK_a:
				transform->velocity.x = 0;
				break;
			case SDLK_d:
				transform->velocity.x = 0;
				break;
			case SDLK_s:
				transform->velocity.y = 0;
				break;
			default:
				break;
			}
		}
	}
};