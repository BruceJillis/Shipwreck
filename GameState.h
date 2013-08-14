#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Game.h"

class GameState {
	public:
		virtual void Init(Game* game) = 0;
		virtual void Clean() = 0;

		virtual void Pause() = 0;
		virtual void Resume() = 0;

		virtual void HandleEvents(Game* game) = 0;
		virtual void Update(Game* game) = 0;
		virtual void Draw(Game* game) = 0;
		
		virtual void Remove(GameObject* go);
		virtual void Add(GameObject* go);
		
		void ChangeState(Game* game, GameState* state) {
			game->ChangeState(state);
		}

	protected:
		GameState() { }
};
#endif
