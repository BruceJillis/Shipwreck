#include <stdlib.h>
#include <time.h>
#include "Game.h"
#include "GameState.h"
#include "GameObject.h"
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"

void Game::Init(const char* title, int w, int h, int bpp, bool fullscreen) {
	// seed random number generator
	srand((unsigned)time(0));
	// initialize SDL and all sub modules
	SDL_Init(SDL_INIT_EVERYTHING);
	// initialize TrueType font module
	TTF_Init();
	// set window caption
	SDL_WM_SetCaption(title, title);
	// determine flags 
	int flags = SDL_NOFRAME | SDL_DOUBLEBUF | SDL_HWSURFACE;
	if ( fullscreen ) {
		flags = SDL_FULLSCREEN;
	}
	m_pScreen = SDL_SetVideoMode(w, h, bpp, flags);
	if ((w == 0) && (h == 0)) {
		// get info from SDL
		const SDL_VideoInfo* info = SDL_GetVideoInfo();
		width = info->current_w;
		height = info->current_h;
	} else {
		width = w;
		height = h;
	}
	m_bFullscreen = fullscreen;
	m_bRunning = true;
	printf("Game: Init %d X %d @ %dbpp\n", width, height, bpp);
}


#define MAXIMUM_FRAME_RATE 200
#define MINIMUM_FRAME_RATE 15
#define UPDATE_INTERVAL (1.0 / MAXIMUM_FRAME_RATE)
#define MAX_CYCLES_PER_FRAME (MAXIMUM_FRAME_RATE / MINIMUM_FRAME_RATE)
void Game::Run() {
	static double lastFrameTime = 0.0;
	static double cyclesLeftOver = 0.0;
	double currentTime;
	double updateIterations;
	
	while ( this->Running() ) {
		currentTime = SDL_GetTicks();
		updateIterations = ((currentTime - lastFrameTime) + cyclesLeftOver);

		if (updateIterations > (MAX_CYCLES_PER_FRAME * UPDATE_INTERVAL)) {
			updateIterations = (MAX_CYCLES_PER_FRAME * UPDATE_INTERVAL);
		}

		while ( updateIterations > UPDATE_INTERVAL ) {
			updateIterations -= UPDATE_INTERVAL;
			this->HandleEvents();
			this->Update();
		}
		
		cyclesLeftOver = updateIterations;
		lastFrameTime = currentTime;

		this->Draw();
	}
}


void Game::ChangeState(GameState* state) {
	// cleanup the current state
	if ( !states.empty() ) {
		states.back()->Clean();
		states.pop_back();
	}
	// store and init the new state
	states.push_back(state);
	states.back()->Init(this);
}

void Game::PushState(GameState* state) {
	// pause current state
	if ( !states.empty() ) {
		states.back()->Pause();
	}
	// store and init the new state
	states.push_back(state);
	states.back()->Init(this);
}

void Game::PopState() {
	// cleanup the current state
	if ( !states.empty() ) {
		states.back()->Clean();
		states.pop_back();
	}
	// resume previous state
	if ( !states.empty() ) {
		states.back()->Resume();
	}
}

void Game::Remove(GameObject* go) {
	states.back()->Remove(go);
}

void Game::Add(GameObject* go) {
	states.back()->Add(go);
}

void Game::HandleEvents() {
	states.back()->HandleEvents(this);
}

void Game::Update() {
	states.back()->Update(this);
}

void Game::Draw() {
	states.back()->Draw(this);
}

void Game::Clean() {
	while ( !states.empty() ) {
		states.back()->Clean();
		states.pop_back();
	}	
	// shutdown TTF & SDL
	TTF_Quit();
	SDL_Quit();
}
