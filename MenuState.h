#ifndef _MENU_STATE_H_
#define _MENU_STATE_H_

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "GameState.h"
#include "Sprite.h"

class MenuState : public GameState {
	public:
		void Init(Game* game);
		void Clean();

		void Pause();
		void Resume();

		void HandleEvents(Game* game);
		void Update(Game* game);
		void Draw(Game* game);

		// Implement Singleton Pattern
		static MenuState* Instance() {
			return &m_MenuState;
		}
	protected:
		MenuState() {}

	private:
		static MenuState m_MenuState;
		SDL_Surface* message1;
		SDL_Surface* message2;
		TTF_Font* font1;
		TTF_Font* font2;
};
#endif
