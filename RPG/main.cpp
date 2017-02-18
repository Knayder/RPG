#include "Game.h"
#include "Scene.h"

int main() {
	Game &game = Game::Instance();
	game.run();
	
	return 0;
}