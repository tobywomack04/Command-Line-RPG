#include "Player.h"
#include "Enemy.h"
#include "GameCharacter.h"
#include <list>

using namespace std;

class Game {
private:
	int weather; // Counter used to determine weather cycle
	bool fog; // Boolean for whether fog is active
	GameCharacter* player; // Player character
	GameCharacter* enemy1; // Enemy1 character
	GameCharacter* enemy2; // Enemy2 character
	GameCharacter* enemy3; // Enemy3 character
	GameCharacter* enemy4; // Enemy4 character
	list<GameCharacter*> lpGameCharacters; // Create a list of GameCharacter pointers

public:
	Game();
	void init(); // Initialises game characters and adds them to an iterator
	void introduction(); // Outlines the players goal
	void render(); // Cycles through the list of GameCharacter (enemy and player objects) and call the render function for each object
	void update(); // Cycles through the list of GameCharacter (enemy and player objects) and call the update function for each object
	void battle(); // Checks whether two characters are on the same tile, if so initiates a battle
	void stats(); // Cycle through the list of GameCharacters ( enemy and player objects) and call the stats function for each object
	void clean(); // Remove any object from the list that has a health value of 0
	void printMap(); // Prints the map with all game character locations
	bool checkWin(); // Checks for one character within the iterator
	void win(); // Outputs a win messsage once win condition has been met
};

