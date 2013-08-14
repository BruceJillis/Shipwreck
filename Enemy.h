#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"
#include "Player.h"
#include "functions.h"

class Enemy : public GameObject {
	public:
		Enemy(Game* game, SDL_Surface* bg) : GameObject(game) {
			background = bg;
			// initialize dimensions
			GameObject::w = 64;
			GameObject::h = 96;
			velocity = Vector2(0.7f, 0.7f);
			// choose a wall
			int wall = (int)RandomFloatRange(0, 4);
			if (wall == 0) {
				// top
				position = Vector2(((game->GetScreen()->w / 2) - (background->w / 2)) + RandomFloatRange(0.0f, (float)(background->w - h)), (game->GetScreen()->h / 2) - (background->h / 2));
			} else if (wall == 1) {
				// left
				position = Vector2((game->GetScreen()->w / 2) - (background->w / 2), ((game->GetScreen()->h / 2) - (background->h / 2)) + RandomFloatRange(0.0f, (float)(background->h - h)));
			} else if (wall == 2) {
				// bottom
				position = Vector2(((game->GetScreen()->w / 2) - (background->w / 2)) + RandomFloatRange(0.0f, (float)(background->w - w)), (game->GetScreen()->h / 2) + (background->h / 2) - h);
			} else if (wall == 3) {
				// right
				position = Vector2((game->GetScreen()->w / 2) + (background->w / 2) - w, ((game->GetScreen()->h / 2) - (background->h / 2)) + RandomFloatRange(0.0f, (float)(background->h - 96)));
			}
		}

		void Draw();
		bool CollidesWith(GameObject* go);
		
		// ai routines
		bool CanAttackPlayer(GameObject* go, Player* p);
	protected:
		SDL_Surface* m_pSprite;
		SDL_Surface* background;
};
#endif
