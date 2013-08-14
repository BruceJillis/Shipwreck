#ifndef BULLET_H
#define BULLET_H

#include "GameObject.h"
#include "Player.h"
#include "constants.h"

class Bullet : public GameObject {
	public:
		Bullet(Game* game, SDL_Surface* bg, GameObject* go, Vector2 d, int _type = PLAYER_BULLET) : GameObject(game) {
			Load(const_cast<char *>("assets/images/bullets1x8.png"));
			background = bg;
			object = go;
			// set dimensions
			w = 24;
			h = 24;
			// copy direction from player
			direction = d;
			if (direction == Vector2::ZERO) {
				direction = Vector2::UP;
			}
			// set speed and velocity
			velocity = Vector2(1.4f, 1.4f);
			// set type (defaults to 2)
			type = _type;
			// setup position of the bullets
			if (direction == Vector2::UP) {
				tx = 0; ty = 0; tw = w; th = h;
			 	position = Vector2(object->position.x + (object->w / 2.0f) - (w / 2.0f), object->position.y);
			} else if (direction == Vector2::RIGHTUP) {
				tx = w; ty = 0; tw = w; th = h;
				position = Vector2(object->position.x + object->w, object->position.y + (object->h / 2.0f));
			} else if (direction == Vector2::RIGHT) {
				tx = w*2; ty = 0; tw = w; th = h;				
				position = Vector2(object->position.x + object->w, object->position.y + (object->h / 2.0f));
			} else if (direction == Vector2::RIGHTDOWN) {
				tx = w*3; ty = 0; tw = w; th = h;				
				position = Vector2(object->position.x + object->w, object->position.y + (object->h / 2.0f));
			} else if (direction == Vector2::DOWN) {
				tx = w*4; ty = 0; tw = w; th = h;
 				position = Vector2(object->position.x + (object->w / 2.0f) - (w / 2.0f), object->position.y + object->h);			
			} else if (direction == Vector2::LEFTDOWN) {
				tx = w*5; ty = 0; tw = w; th = h;				
				position = Vector2(object->position.x, object->position.y + (object->h / 2.0f));
			} else if (direction == Vector2::LEFT) {
				tx = w*6; ty = 0; tw = w; th = h;				
				position = Vector2(object->position.x, object->position.y + (object->h / 2.0f));
			} else if (direction == Vector2::LEFTUP) {
				tx = w*7; ty = 0; tw = w; th = h;
				position = Vector2(object->position.x, object->position.y + (object->h / 2.0f));
			} else {
				tx = 0; ty = 0; tw = w; th = h;								
			}
		}

		void Update();
		void Draw();
		bool CollidesWith(GameObject* go);
		void ResolveCollision(GameObject* go);
	protected:
		SDL_Surface* m_pSprite;
		SDL_Surface* background;
		GameObject* object;

		// spritesheet coordinates
		int tx;
		int ty;
		int tw;
		int th;
};
#endif
