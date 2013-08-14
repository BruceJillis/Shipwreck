#ifndef SPIKOTICON_H
#define SPIKOTICON_H

#include "Player.h"
#include "Enemy.h"
#include "constants.h"

class Spikoticon : public Enemy {
	public:
		Spikoticon(Game* game, SDL_Surface* bg, Player* p) : Enemy(game, bg) {
			Load(const_cast<char *>("assets/images/bad4x8.png"));
			player = p;
			type = SPIKOTICON;
			score = 300;
		}

		void Update();
	private:
	    void NextDirection();			
		Player* player;
		int steps;		
};
#endif
