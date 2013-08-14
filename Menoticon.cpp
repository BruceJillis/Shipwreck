#include "Menoticon.h"
#include "MenoticonBullet.h"
#include "constants.h"

void Menoticon::Update() {
	// store old position
	_position = position;
	// shoot
	if (CanAttackPlayer(this, player)) {
		if (bullets <= 0) {
			bullets = 375;
			// calculate direction to player
			Vector2 d = player->position - position;
			d.Normalize();
			d.Round();
			//			
			GameObject* go = new MenoticonBullet(game, background, this, d);
			game->Add(go);
		}
	}
	bullets -= 1;
	// move
	position += direction * velocity;
	if (steps == 0) {
		NextDirection();
	}
	steps -= 1;
	// constrain x to the background
	int mx = (game->GetScreen()->w / 2);
	int mbx = (background->w / 2);
	if ((position.x + w) > mx + mbx) {
		position.x = mx + mbx - w;
		NextDirection();
	}
	if (position.x < (mx - mbx)) {
		position.x = mx - mbx;
		NextDirection();
	}
	// constrain y to the background
	int my = (game->GetScreen()->h / 2);
	int mby = (background->h / 2);
	if ((position.y + h) > (my + mby)) {
		position.y = my + mby - h;
		NextDirection();
	}
	if (position.y < (my - mby)) {
		position.y = my - mby;
		NextDirection();
	}
}

void Menoticon::NextDirection() {
	// random direction
	//direction = Vector2(1.0 - RandomFloatRange(0.0, 3.0), 1.0 - RandomFloatRange(0.0, 3.0));
	//direction.Round();	
	int type = (int)RandomFloatRange(0, 4);
	steps = (int)RandomFloatRange(10, 500);
	// spawn enemy
	switch(type) {
		case 0: {
			direction = Vector2::UP;
			break;
		}
		case 1: {
			direction = Vector2::DOWN;
			break;
		}
		case 2: {
			direction = Vector2::LEFT;
			break;
		}
		case 3: {
			direction = Vector2::RIGHT;
			break;
		}
	}
}

