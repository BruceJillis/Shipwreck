#ifndef SHIPWRECK_H
#define SHIPWRECK_H

#include "GameObject.h"
#include "constants.h"

class Shipwreck : public GameObject {
	public:
		Shipwreck(Game* game, SDL_Surface* bg) : GameObject(game) {
			Load(const_cast<char *>("assets/images/spacewreck1x8.png"));
			background = bg;
			// initialize position and dimensions
			w = 200;
			h = 184;
			position = Vector2((game->GetScreen()->w / 2) - (GameObject::w / 2), (game->GetScreen()->h / 2) - (GameObject::h / 2));
			velocity = Vector2(0.0f, 0.0f);
			// does this object collide
			collision = false;
			// set type
			type = SHIPWRECK;
		}
		
		bool CollidesWith(GameObject* go);
		void ResolveCollision(GameObject* go);
		
	private:
		SDL_Surface* background;
};
#endif
