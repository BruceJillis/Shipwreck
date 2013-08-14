#include "Enemy.h"
#include "constants.h"

void Enemy::Draw() {
	Sprite::Draw(game->GetScreen(), GameObject::m_pSprite, (int)(position.x + 0.5f), (int)(position.y + 0.5f));
}

bool Enemy::CollidesWith(GameObject* go) {
	switch(go->type) {
		case PLAYER: 
		case PLAYER_BULLET: 
			return Collides(go);
			break;
		case SHIPWRECK:
		case RUNOTICON:
		default:
			return false; // no collision
			break;
	}
	return false; // default too no collision
}

bool Enemy::CanAttackPlayer(GameObject* go, Player* p) {
	return true;
}
