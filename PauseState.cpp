#include <stdio.h>

#include "SDL/SDL.h"
#include "Game.h"
#include "PauseState.h"

PauseState PauseState::m_PauseState;

void PauseState::Init(Game *game) {
	font = TTF_OpenFont("assets/fonts/tpf.ttf", 28);
	SDL_Color textColor = { 255, 255, 255 };
	message = TTF_RenderText_Solid(font, "Paused", textColor);
}

void PauseState::Clean() {
	SDL_FreeSurface(message);
	TTF_CloseFont(font);
}

void PauseState::Resume() {
	// do nothing
}

void PauseState::Pause() {
	// do nothing
}

void PauseState::HandleEvents(Game* game) {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				game->Quit();
				break;

			case SDL_KEYDOWN:
				switch(event.key.keysym.sym) {
					case SDLK_ESCAPE:
						game->PopState();
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

void PauseState::Update(Game* game) {
	// do nothing
}

void PauseState::Remove(GameObject* go) {
	// do nothing
}

void PauseState::Draw(Game* game) {
	SDL_FillRect(game->GetScreen(), NULL, 0x000000);
	Sprite::Draw(game->GetScreen(), message, (game->GetScreen()->w / 2) - (message->w / 2), (game->GetScreen()->h / 2) - (message->h / 2));
	SDL_Flip(game->GetScreen());
}
