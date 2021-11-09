#pragma once

#include "Components.h"
#include "../game.h"

class KeyboardController : public Component {
public:
	TransformComponent *transform;
	SpriteComponent *sprite;
	void init() override {
		transform = &entity->getComponent<TransformComponent>();
		sprite = &entity->getComponent < SpriteComponent>();
	}
	void update() override {
		if (_game::event.type == SDL_KEYDOWN) {
			switch (_game::event.key.keysym.sym) {
			case SDLK_w:
				transform->velocity.y = -1;
				//sprite->Play("Walk");
				break;
			case SDLK_a:
				transform->velocity.x = -1;
				//sprite->Play("Walk");
				sprite->spriteFlip = SDL_FLIP_HORIZONTAL;
				break;
			case SDLK_d:
				transform->velocity.x = 1;
				//sprite->Play("Walk");
				break;
			case SDLK_s:
				transform->velocity.y = 1;
				//sprite->Play("Walk");
				break;
			default:
				break;
			}
		}
		if (_game::event.type == SDL_KEYUP) {
			switch (_game::event.key.keysym.sym) {
			case SDLK_w:
				transform->velocity.y = 0;
				sprite->Play("Idle");
				break;
			case SDLK_a:
				transform->velocity.x = 0;
				sprite->Play("Idle");
				sprite->spriteFlip = SDL_FLIP_NONE;
				break;
			case SDLK_d:
				transform->velocity.x = 0;
				sprite->Play("Idle");
				break;
			case SDLK_s:
				transform->velocity.y = 0;
				sprite->Play("Idle");
				break;
			default:
				break;
			}
		}
	}
};