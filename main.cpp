#include "Game.h"
#include "MenuState.h"
#include <iostream>

int main(int argc, char* argv[]) {
	Game game;
	game.Init("ShipWreck", 0, 0, 8, true);
	game.ChangeState(MenuState::Instance());
	game.Run();
	game.Clean();
	return 0;
}
