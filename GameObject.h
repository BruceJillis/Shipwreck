#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Game.h" 
#include "Vector2.h" 
#include "Sprite.h"

class GameObject {
	public:
		GameObject(Game* g) {
			game = g;
			type = 0; // undefined
		}
		
		virtual ~GameObject() {};
		
		virtual void Load(char* filename);
		virtual void Update();
		virtual void Draw();
		virtual void Clean();
		bool Collides(GameObject *h);
		virtual bool CollidesWith(GameObject* go) = 0;
		virtual void ResolveCollision(GameObject* go);

		// public properties 
		Game* game;
		SDL_Surface* m_pSprite;
		// type of gameobject (for selective collision checks)
		int type;
		int score; // either score for killing or total obtained score
		// does this GameObject collide?
		bool collision;		
		// old position
		float _x;
		float _y;
		// position
		float x;
		float y;
		// dimensions
		int w;
		int h;
		// velocity
		float vx;
		float vy;
		// direction
		Vector2 direction;
		Vector2 velocity;
		Vector2 position;
		// old position
		Vector2 _position;
		Vector2 _direction;
};
#endif
