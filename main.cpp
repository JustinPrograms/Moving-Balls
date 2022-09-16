#include "Game.h"

int main() {

	// Init srand
	srand(static_cast<unsigned>(time(0)));

	// Init game engine
	Game game;

	// Game loop
	while (game.running()) {
		game.update();
		game.render();
	}

	return 0;
}