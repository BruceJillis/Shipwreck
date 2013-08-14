#include <stdio.h>

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "Game.h"
#include "MenuState.h"
#include "PlayState.h" 

MenuState MenuState::m_MenuState;

void MenuState::Init(Game *game) {	
	font1 = TTF_OpenFont("assets/fonts/tpf.ttf", 28);
	font2 = TTF_OpenFont("assets/fonts/tpf.ttf", 14);
	SDL_Color textColor = { 255, 255, 255 };
	message1 = TTF_RenderText_Solid(font1, "Menu State", textColor);
	message2 = TTF_RenderText_Solid(font2, "Press Space To Start", textColor);	
}

void MenuState::Clean() {
	SDL_FreeSurface(message1);
	SDL_FreeSurface(message2);
	TTF_CloseFont(font1);
	TTF_CloseFont(font2);
}

void MenuState::Pause() {
	// do nothing
}

void MenuState::Resume() {
	// do nothing
}


void MenuState::HandleEvents(Game* game) {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				game->Quit();
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
					case SDLK_ESCAPE:
					    game->Quit();
						break;
					case SDLK_SPACE:
						game->PushState(PlayState::Instance());
						break;
					default:
						/* do nothing */
						break;
			}
		}
	}
}

void MenuState::Update(Game* game) {
}

void MenuState::Draw(Game* game) {
	SDL_FillRect(game->GetScreen(), NULL, 0x000000);
	Sprite::Draw(game->GetScreen(), message1, (game->GetScreen()->w / 2) - (message1->w / 2), (game->GetScreen()->h / 2) - (message1->h / 2));
	Sprite::Draw(game->GetScreen(), message2, (game->GetScreen()->w / 2) - (message2->w / 2), (game->GetScreen()->h / 2) - (message2->h / 2) + 28);
	SDL_Flip(game->GetScreen());
}
