#include "GameObject.h"
#include "Vector2.h"
#include "SDL_collide.h"

void GameObject::Load(char* filename) {
	m_pSprite = Sprite::Load(filename);
}

void GameObject::Update() {
	// do nothing
}

bool GameObject::Collides(GameObject* o) {
	// make the rects
	SDL_Rect a = {(int)(position.x + 0.5f), (int)(position.y + 0.5f), w, h};
	SDL_Rect b = {(int)(o->position.x + 0.5f), (int)(o->position.y + 0.5f), o->w, o->h};
				
	// test if we have a collision
	if (SDL_CollideBoundingBox(a, b) != 0) {
		if (SDL_CollidePixel(m_pSprite, position.x, position.y, o->m_pSprite, o->position.x, o->position.y)) {
			return true;
		}
		//return true;
	}
	return false;
}

void GameObject::ResolveCollision(GameObject* go) {
	position = _position;
}

void GameObject::Draw() {
	Sprite::Draw(game->GetScreen(), m_pSprite, (int)(position.x + 0.5f), (int)(position.y + 0.5f));
}

void GameObject::Clean() {
    SDL_FreeSurface(m_pSprite);
	delete this;
}
