#include <stdio.h>
#include <typeinfo>

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "Vector2.h"
#include "Game.h"
#include "Runoticon.h"
#include "Menoticon.h"
#include "Spikoticon.h"
#include "PlayState.h"
#include "PauseState.h"
#include "Bullet.h"

PlayState PlayState::m_PlayState;

void PlayState::Init(Game* game) {	
	background = Sprite::Load(const_cast<char *>("assets/images/background1x8.png"));
	// shipwreck
	shipwreck = new Shipwreck(game, background);
	GameObjects.push_back(shipwreck);
	// player
	player = new Player(game, background);
	GameObjects.push_back(player);
	// enemies
	GameObject* go = new Runoticon(game, background, player);	
	GameObjects.push_back(go);
	// spawn
	spawns = 100;
}

void PlayState::Clean() {
	SDL_FreeSurface(background);
	for(unsigned int i = 0;i < GameObjects.size(); i++) {
		GameObjects[i]->Clean();
	}
	GameObjects.clear();
}

void PlayState::Pause() {
	// do nothing
}

void PlayState::Resume() {
	// do nothing
}

void PlayState::HandleEvents(Game* game) {
	SDL_Event event;

	while ( SDL_PollEvent(&event) ) {
		switch (event.type) {
			case SDL_QUIT:
				game->Quit();
				break;
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym) {
					case SDLK_ESCAPE:
						game->PopState();
						break;
					case SDLK_RETURN: {
						// spawn enemy
						GameObject* go = new Runoticon(game, background, player);	
						game->Add(go);
						break;
					}
					case SDLK_p:
						game->PushState(PauseState::Instance());
						break;
					default:
						/* do nothing */
						break;
				}
		}
	}
}

void PlayState::Update(Game* game) {
	for(unsigned int i = 0;i < GameObjects.size();i++) {
		GameObjects[i]->Update();
	}
	// auto spawn enemies
	if (spawns == 0) {
		spawns = 500;
		int type = (int)RandomFloatRange(0, 3);
		// spawn enemy
		switch(type) {
			case 0: {
				GameObject* go = new Runoticon(game, background, player);	
				game->Add(go);
				break;
			}
			case 1: {
				GameObject* go = new Menoticon(game, background, player);	
				game->Add(go);
				break;
			}
			case 2: {
				GameObject* go = new Spikoticon(game, background, player);	
				game->Add(go);
				break;				
			}
		}
	}
	spawns--;
	// 
	for(unsigned int i = 0;i < GameObjects.size(); i++) {
		for(unsigned int j = 0;j < GameObjects.size(); j++) {
			if (i == j) {
				continue;
			}
			if (GameObjects[i]->CollidesWith(GameObjects[j])) {
				GameObjects[i]->ResolveCollision(GameObjects[j]);
			}
		}
	}
}

void PlayState::Draw(Game* game)  {
	SDL_FillRect(game->GetScreen(), NULL, 0x000000);
	Sprite::Draw(game->GetScreen(), background, (game->GetScreen()->w / 2) - (background->w / 2), (game->GetScreen()->h / 2) - (background->h / 2));
	for(unsigned int i = 0; i < GameObjects.size(); i++) {
		GameObjects[i]->Draw();
	}
	SDL_Flip(game->GetScreen());
}

void PlayState::Remove(GameObject* go) {
	for(unsigned int i = 0; i < GameObjects.size(); i++) {
		if ( GameObjects[i] == go ) {
			GameObjects.erase(GameObjects.begin() + i);
		}
	}
}

void PlayState::Add(GameObject* go) {
	GameObjects.push_back(go);	
}
