#ifndef _GAME_H_
#define _GAME_H_

#include "SDL/SDL.h"
#include "Sprite.h"
#include <vector>

class GameState;
class GameObject;

class Game {
	public:
		Game() {}
		
		void Init(const char* title, int width, int height, int bpp, bool fullscreen);
		void Run();
		void HandleEvents();
		void Update();
		void Draw();
		void Clean();
		
		// state management
		void ChangeState(GameState* state);
		void PushState(GameState* state);
		void PopState();
		
		// entity management
		void Remove(GameObject* go);
		void Add(GameObject* go);
		
		// misc utility functions
		SDL_Surface* GetScreen() { 
			return m_pScreen; 
		}
		
		bool Running() { 
			return m_bRunning; 
		};
		
		void Quit() { 
			m_bRunning = false; 
		};
		
		// width and height of the main game surface
		int width;
		int height;
		
	private:
		bool m_bRunning;
		bool m_bFullscreen;
		SDL_Surface* m_pScreen;
		std::vector<GameState*> states;
};

#endif
