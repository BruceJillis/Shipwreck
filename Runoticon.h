#ifndef RUNOTICON_H
#define RUNOTICON_H

#include "Player.h"
#include "Enemy.h"
#include "constants.h"

class Runoticon : public Enemy {
	public:
		Runoticon(Game* game, SDL_Surface* bg, Player* p) : Enemy(game, bg) {
			Load(const_cast<char *>("assets/images/bad3x8.png"));
			player = p;
			type = RUNOTICON;
			score = 100;
		}

		void Update();
	private:
		Player* player;
};
#endif
