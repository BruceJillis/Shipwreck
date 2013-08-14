#ifndef _PAUSE_STATE_H_
#define _PAUSE_STATE_H_

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "GameState.h"
#include "Sprite.h"

class PauseState : public GameState {
	public:
		void Init(Game *game);
		void Clean();

		void Pause();
		void Resume();

		void HandleEvents(Game* game);
		void Update(Game* game);
		void Draw(Game* game);
		
		void Remove(GameObject* go);

		static PauseState* Instance() {
			return &m_PauseState;
		}

	protected:
		PauseState() {}

	private:
		static PauseState m_PauseState;
		SDL_Surface* message;
		TTF_Font* font;
};
#endif
