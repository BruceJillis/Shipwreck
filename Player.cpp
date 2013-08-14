#include "Player.h"
#include "Vector2.h"
#include "Bullet.h"
#include "DeathState.h"
#include "constants.h"

void Player::Update() {
	Uint8* keystates = SDL_GetKeyState(NULL);
	// store old position
	_position = position;
	// reset direction vector
	direction.x = 0;
	direction.y = 0;
	if( keystates[SDLK_DOWN] ) {
		direction += Vector2::DOWN;
		// switch sprite 
		tx = tw * 3;
		ty = 0;
	}
	if( keystates[SDLK_UP] ) {
		direction += Vector2::UP;
		// switch sprite
		tx = tw * 2;
		ty = 0;
	}
	if( keystates[SDLK_LEFT] ) {
		direction += Vector2::LEFT;
		// switch sprite
		tx = 0;
		ty = 0;
	}
	if( keystates[SDLK_RIGHT] ) {
		direction += Vector2::RIGHT;
		// switch sprite
		tx = tw;
		ty = 0;
	}
	// shoot bullets
	if( keystates[SDLK_SPACE] ) {
		if (bullets <= 0) {
			bullets = 75;
			GameObject* go = new Bullet(game, background, this, this->direction);
			game->Add(go);
		}
	}
	bullets -= 1;
	// update position
	position += direction * velocity;
	// constrain x to the background
	int mx = (game->GetScreen()->w / 2);
	int mbx = (background->w / 2);
	if ((position.x + w) > mx + mbx) {
		position.x = mx + mbx - w;
	}
	if (position.x < (mx - mbx)) {
		position.x = mx - mbx;
	}
	// constrain y to the background
	int my = (game->GetScreen()->h / 2);
	int mby = (background->h / 2);
	if ((position.y + h) > (my + mby)) {
		position.y = my + mby - h;
	}
	if (position.y < (my - mby)) {
		position.y = my - mby;
	}
}

void Player::Draw() {
	// draw lives
	for(unsigned int i = 0; i < lives; i++) {
		Sprite::Draw(game->GetScreen(), heart, (game->GetScreen()->w / 2) - (background->w / 2) + (i * 60), 5);
	}
	// render score
	char buffer[10];
	sprintf(buffer, "%8d", score);
	SDL_Color color = { 255, 255, 255 };
	Sprite::Draw(game->GetScreen(), TTF_RenderText_Solid(font, buffer, color), (game->GetScreen()->w / 2) + (background->w / 2) - 235, 12);
	// draw sprite
	Sprite::Draw(game->GetScreen(), GameObject::m_pSprite, (int)(position.x + 0.5f), (int)(position.y + 0.5f), tx, ty, tw, th);
}

bool Player::CollidesWith(GameObject* go) {
	switch(go->type) {
		case RUNOTICON:
		case MENOTICON:
		case MENOTICON_BULLET:
			return Collides(go);
			break;
		case SHIPWRECK:
		case PLAYER:
		case PLAYER_BULLET:
		default:
			return false; // no collision
			break;
	}
	return false; // default too no collision
}

void Player::ResolveCollision(GameObject* go) {
	lives--;
	game->Remove(go);
	if (lives == 0) {
		game->ChangeState(DeathState::Instance());
	}
}

