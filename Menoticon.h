#ifndef MENOTICON_H
#define MENOTICON_H

#include "Player.h"
#include "Enemy.h"
#include "constants.h"

class Menoticon : public Enemy {
	public:
		Menoticon(Game* game, SDL_Surface* bg, Player* p) : Enemy(game, bg) {
			Load(const_cast<char *>("assets/images/bad2x8.png"));
			player = p;
			type = MENOTICON;
			score = 200;
			bullets = 0;
			NextDirection();
		}

		void Update();		
	private:
	    void NextDirection();			
		Player* player;
		int bullets;
		int steps;
};
#endif
