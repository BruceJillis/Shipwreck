#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "SDL/SDL_ttf.h"
#include "constants.h"

class Player : public GameObject {
	public:
		Player(Game* game, SDL_Surface* bg) : GameObject(game) {
			background = bg;
			Load(const_cast<char *>("assets/images/good1x8.png"));
			heart = Sprite::Load(const_cast<char *>("assets/images/heart1x8.png")); // 56 x 40
			font = TTF_OpenFont("assets/fonts/tpf.ttf", 40);
			// initialize position and dimensions
			GameObject::w = 64;
			GameObject::h = 96;
			// vector2 implementation
			velocity = Vector2(0.7f, 0.7f);
			position = Vector2((game->GetScreen()->w / 2.0f) - (w / 2.0f), (game->GetScreen()->h / 2.0f) - (h / 2.0f));
			// select the first sprite in the sheet
			tx = 0;
			ty = 0;
			tw = 64;
			th = 96;
			// set type
			type = PLAYER;
			// bullet counter
			bullets = 0;
			// number of lives
			lives = 15;
			// current score
			score = 0;
		}

		void Update();
		void Draw();
		bool CollidesWith(GameObject* go);
		virtual void ResolveCollision(GameObject* go);
		
	private:
		SDL_Surface* m_pSprite;
		SDL_Surface* background;
		SDL_Surface* heart;
		TTF_Font* font;		
		
		int bullets;
		int lives;
		
		// spritesheet coordinates
		int tx;
		int ty;
		int tw;
		int th;
};
#endif
