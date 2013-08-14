#include "Shipwreck.h"

bool Shipwreck::CollidesWith(GameObject* go) {
	return false;
}

void Shipwreck::ResolveCollision(GameObject* go) {
	position = _position;
}
