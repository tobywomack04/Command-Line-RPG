#include "Game.h"
#include "Enemy.h"
#include "GameCharacter.h"
#include "Player.h"
#include <vector>
#include <list>

// Main method
int main() {
	Game game; // Create a game object
	game.init(); // Initialises each game character
	game.introduction(); // Displays game introduction

	for (int i = 0; i < 100; i++) {
		while (!game.checkWin()) {
			game.render(); // Displays the ID, x cord and y cord of each game character 
			game.printMap(); // Prints the map with all game character locations
			game.update(); // Cycles through the list of GameCharacter (enemy and player objects) and call the update function for each object
			game.battle(); // Checks whether two characters are on the same tile, if so initiates a battle
			game.stats(); // Cycle through the list of GameCharacters ( enemy and player objects) and call the stats function for each object
			game.clean(); // Remove any object from the list that has a health value of 0
		}
	} // End of for loop (runs game 100 times or until one game character remains)

	game.stats();
	game.win(); // Outputs a win messsage once win condition has been met

	return 0;
} // End of main