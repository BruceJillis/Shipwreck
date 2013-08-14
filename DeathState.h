#ifndef _MENU_STATE_H_
#define _MENU_STATE_H_

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "GameState.h"
#include "Sprite.h"

class DeathState : public GameState {
	public:
		void Init(Game* game);
		void Clean();

		void Pause();
		void Resume();

		void HandleEvents(Game* game);
		void Update(Game* game);
		void Draw(Game* game);

		// Implement Singleton Pattern
		static DeathState* Instance() {
			return &m_State;
		}
		
	protected:
		DeathState() {}

	private:
		static DeathState m_State;
		SDL_Surface* background;
		SDL_Surface* message;
		TTF_Font* font;
};
#endif
