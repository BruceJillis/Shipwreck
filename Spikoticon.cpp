#include "Spikoticon.h"
#include <math.h>

void Spikoticon::Update() {
	
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

void Spikoticon::NextDirection() {
	// random direction	
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
