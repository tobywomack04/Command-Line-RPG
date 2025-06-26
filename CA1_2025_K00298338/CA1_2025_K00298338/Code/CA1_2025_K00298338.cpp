#include "Game.h"
#include "Enemy.h"
#include "GameCharacter.h"
#include "Player.h"
#include <vector>
#include <list>

int main() {
	Game game;
	game.init();

	for (int i = 0; i < 100; i++) {
		game.render();
		game.update();
		game.battle();
		game.stats();
		game.clean();
	} // End of for loop

	game.stats();

	return 0;
}