#include "Bullet.h"
#include "constants.h"

void Bullet::Update() {	
	position += direction * velocity;
	// constrain x to the background
	int mx = (game->GetScreen()->w / 2);
	int mbx = (background->w / 2);
	if (position.x > (mx + mbx)) {
		game->Remove(this);
	}
	if (position.x < (mx - mbx)) {
		game->Remove(this);
	}
	// constrain y to the background
	int my = (game->GetScreen()->h / 2);
	int mby = (background->h / 2);
	if (position.y > (my + mby)) {
		game->Remove(this);
	}
	if (position.y < (my - mby)) {
		game->Remove(this);
	}
}

bool Bullet::CollidesWith(GameObject* go) {
	switch(go->type) {
		case RUNOTICON: 
		case MENOTICON: 
	    case SPIKOTICON:
			return Collides(go);
			break;
		case SHIPWRECK: 
		case PLAYER_BULLET:
		case PLAYER:
		case MENOTICON_BULLET:
			return false; // no collision
			break;
	}
	return false; // default too no collision
}

void Bullet::ResolveCollision(GameObject* go) {
	object->score += go->score;
	game->Remove(this);
	game->Remove(go);
}

void Bullet::Draw() {
	Sprite::Draw(game->GetScreen(), GameObject::m_pSprite, (int)(position.x + 0.5f), (int)(position.y + 0.5f), tx, ty, tw, th);
}
