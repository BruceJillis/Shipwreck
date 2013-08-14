#include "Runoticon.h"
#include <math.h>

void Runoticon::Update() {
	// store old position
	_position = position;
	// calculate new position
	Vector2 distance = player->position - position;
	distance.Normalize();
	position += distance * velocity;
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

