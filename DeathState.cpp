#include <stdio.h>

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "Game.h"
#include "DeathState.h"
#include "PlayState.h" 

DeathState DeathState::m_State;

void DeathState::Init(Game *game) {	
	font = TTF_OpenFont("assets/fonts/tpf.ttf", 40);
	SDL_Color textColor = { 255, 0, 0 };
	message = TTF_RenderText_Solid(font, "You Died!", textColor);
	background = Sprite::Load(const_cast<char *>("assets/images/death.png"));
}

void DeathState::Clean() {
	SDL_FreeSurface(message);
	TTF_CloseFont(font);
}

void DeathState::Pause() {
}

void DeathState::Resume() {
}


void DeathState::HandleEvents(Game* game) {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				game->Quit();
				break;
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym) {
					case SDLK_ESCAPE:
					    game->Quit();
						break;
					case SDLK_SPACE:
						game->PopState();
						break;
					default:
						/* do nothing */
						break;
			}
		}
	}
}

void DeathState::Update(Game* game) {
}

void DeathState::Draw(Game* game) {
	SDL_FillRect(game->GetScreen(), NULL, 0x000000);
	Sprite::Draw(game->GetScreen(), background, (game->GetScreen()->w / 2) - (background->w / 2) + 50, (game->GetScreen()->h / 2) - (background->h / 2) + 50);	
	Sprite::Draw(game->GetScreen(), message, (game->GetScreen()->w / 2) - (message->w / 2), (game->GetScreen()->h / 2) - (message->h / 2));
	SDL_Flip(game->GetScreen());
}
