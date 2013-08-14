#ifndef _PLAY_STATE_H_
#define _PLAY_STATE_H_

#include "SDL/SDL.h"
#include "GameState.h"
#include "Sprite.h"
#include "Player.h"
#include "Enemy.h"
#include "Shipwreck.h"

class PlayState : public GameState {
	public:
		std::vector<GameObject*> GameObjects;
		
		void Init(Game* game);
		void Clean();

		void Pause();
		void Resume();

		void HandleEvents(Game* game);
		void Update(Game* game);
		void Draw(Game* game);
		
		void Remove(GameObject* go);
		void Add(GameObject* go);

		static PlayState* Instance() {
			return &m_PlayState;
		}

	protected:
		PlayState() {}

	private:
		static PlayState m_PlayState;
		SDL_Surface* background;
		Player* player;
		Shipwreck* shipwreck;
		int spawns;
};
#endif
