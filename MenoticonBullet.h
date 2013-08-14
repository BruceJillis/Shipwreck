#ifndef MENOTICONBULLET_H
#define MENOTICONBULLET_H

#include "Bullet.h"
#include "constants.h"

class MenoticonBullet : public Bullet {
	public:
		MenoticonBullet(Game* game, SDL_Surface* bg, GameObject* go, Vector2 d) : Bullet(game, bg, go, d, MENOTICON_BULLET) {
		}

		bool CollidesWith(GameObject* go);
};
#endif
