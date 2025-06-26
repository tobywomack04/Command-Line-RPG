#include "Game.h"
#include <iostream>
#include <cstdlib>

// Non-paramaterised constructor
Game::Game() {
	weather = 0;
	fog = false;
}

// Initialises all game characters
void Game::init() {
	player = new Player(); // Creating player object
	enemy1 = new Enemy(); // Creating enemy object
	enemy2 = new Enemy(); // Creating enemy object
	enemy3 = new Enemy(); // Creating enemy object
	enemy4 = new Enemy(); // Creating enemy object

	srand(time(0)); // Seeding randomiser

	// Providing characters their values (ID, hp, speed, x, y, no. healing potions))
	player->spawn("p1", (140 + rand() % 31), (2 + rand() % 3), (rand() % 2), (rand() % 10), (1 + rand() % 2));
	enemy1->spawn("e1", (90 + rand() % 61), (1 + rand() % 4), (2 + rand() % 2), (rand() % 10), 0);
	enemy2->spawn("e2", (90 + rand() % 61), (1 + rand() % 4), (4 + rand() % 2), (rand() % 10), 0);
	enemy3->spawn("e3", (90 + rand() % 61), (1 + rand() % 4), (6 + rand() % 2), (rand() % 10), 0);
	enemy4->spawn("e4", (90 + rand() % 61), (1 + rand() % 4), (8 + rand() % 2), (rand() % 10), 0);

	lpGameCharacters.push_back(player);
	lpGameCharacters.push_back(enemy1);
	lpGameCharacters.push_back(enemy2);
	lpGameCharacters.push_back(enemy3);
	lpGameCharacters.push_back(enemy4);
} // End of init function

// Provides some introductory text explaining what the player's goal is
void Game::introduction() {
	cout << "As a valiant knight, you traverse the war-torn kingdom, vanquishing marauding "
		"beasts and rival warlords that threaten the realm.Your quest is to restore order, "
		"prove your strength in battle, and carve your name into legend. With sword in hand "
		"and armor gleaming, you must journey across treacherous lands, slay formidable foes and "
		"bring peace to the kingdom once more." << endl;

	cout << endl; // Used for spacing in the compiler
	cout << "Press enter to begin" << endl;
	cin.get(); // Waiting for enter key to be pressed
} // End of introduction function

// Iterates through each game character and calls their render function
void Game::render() {
	list<GameCharacter*>::const_iterator iter;

	for (iter = lpGameCharacters.begin(); iter != lpGameCharacters.end(); ++iter)
	{
		(*iter)->render();
	}

	cout << endl;
} // End of render function

// Iterates through each game character and calls their update function
void Game::update() {
	list<GameCharacter*>::const_iterator iter;

	for (iter = lpGameCharacters.begin(); iter != lpGameCharacters.end(); ++iter)
	{
		(*iter)->update();
	}
} // End of update function

// Handles player healing and battling between enemies
void Game::battle() {
	list<GameCharacter*>::iterator iter1, iter2;
	int choice = 0; // Integer that stores players choice (1, 2)

	for (iter1 = lpGameCharacters.begin(); iter1 != lpGameCharacters.end(); ++iter1)
	{
		for (iter2 = next(iter1); iter2 != lpGameCharacters.end(); ++iter2)
		{
			if ((*iter1)->getX() == (*iter2)->getX() && (*iter1)->getY() == (*iter2)->getY() && (*iter1)->getID() != (*iter2)->getID())
			{
				cout << "A battle has begun between " << (*iter1)->getID() << " & " << (*iter2)->getID() << endl;
				
				// Ensures only the numbers 1 & 2 can be entered
				do {
					cout << "Will you mend your wounds or battle?" << endl;
					cout << "1. Mend wounds" << endl;
					cout << "2. Battle" << endl;
					cin >> choice;
					cout << endl; // Used for spacing in the compiler
				} while (choice != 1 && choice != 2);

				// If user chooses to heal and has the avaliable health potions
				if (choice == 1 && (*iter1)->getPotionCount() > 0) {
					(*iter1)->heal((*iter1)->getHP() * 0.1);
					cout << "You have but " << (*iter1)->getPotionCount() << " elixirs remaining" << endl;
					cout << endl; // Used for spacing in the compiler
				}
				// If user chooses to heal but doesn't have any health potions avaliable 
				else if ((*iter1)->getPotionCount() == 0) {
					cout << "Your wounds fester, and no elixirs remain to mend them" << endl;
					cout << endl; // Used for spacing in the compiler
				}
					
				if ((*iter1)->getHP() > (*iter2)->getHP())
				{
					cout << "Character " << (*iter2)->getID() << " has perished" << endl;
					(*iter2)->setHP(0);
					(*iter1)->setHP((*iter1)->getHP() * 0.9);
					cout << "Character " << (*iter1)->getID() << " was cut in battle (-10% health)" << endl;
				}
				else if ((*iter1)->getHP() < (*iter2)->getHP())
				{
					cout << "Character " << (*iter1)->getID() << " has perished" << endl;
					(*iter1)->setHP(0);
					(*iter2)->setHP((*iter2)->getHP() * 0.9);
					cout << "Character " << (*iter2)->getID() << " was cut in battle (-10% health)" << endl;
				}
				else {
					cout << "The clash ends in stalemate, neither blade nor spell could "
					"claim victory this day" << endl;
				}
			}
		} // End of for loop (iter2)
	} // End of for loop (iter1)

	cout << endl; // Used for sacing in compiler
} // End of battle function

// Iterates through each game character and calls their stats function
void Game::stats() {
	list<GameCharacter*>::const_iterator iter;

	for (iter = lpGameCharacters.begin(); iter != lpGameCharacters.end(); ++iter)
	{
		(*iter)->stats();
	}

	cout << endl;
} // End of stats function

// Iterates through each game character and removes them from the iterator if they're no longer alive
void Game::clean() {
	list<GameCharacter*>::const_iterator iter;

	for (iter = lpGameCharacters.begin(); iter != lpGameCharacters.end();)
	{
		if ((*iter)->isAlive() == false) {

			iter = lpGameCharacters.erase(iter);
		}
		else {
			++iter;
		}
	}
} // End of clean function

// Updates all locations of player and enemies and displays map
void Game::printMap() {
	list<GameCharacter*>::const_iterator iter;
	const int mapSize = 10;
	string map[mapSize][mapSize];

	// Loop through array and set all spaces to blank
	for (int i = 0; i < mapSize; i++)
	{
		for (int j = 0; j < mapSize; j++)
		{
			map[i][j] = "[ ]";
		} // End of for loop (clean x coordinates of map)
	} // End of for loop (clean y coordinates of map)

	srand(time(0)); // Seeds ranomiser
	int random = rand() % 2; // Random integer used to determine whether the weather will be foggy or clear (0 or 1)
	
	if (fog || random == 0) {
		if (weather % 5 == 2) {
			cout << "The weather becomes foggy" << endl;
			fog = true; // Tells program weather is now foggy
		}
		else if (fog && weather % 5 == 4) {
			cout << "The weather clears" << endl;
			fog = false; // Tells program weather is no longer foggy
		}
	}
	
	for (iter = lpGameCharacters.begin(); iter != lpGameCharacters.end(); ++iter)
	{
		if ((*iter)->getID() == "p1") {
			// Set coordinates of player to 'P' character
			map[(*iter)->getY()][(*iter)->getX()] = "[P]";
		}
		else {
			if (!fog || weather % 5 != 2 && weather % 5 != 3) {
				// Set coordinates of enemy to '*' character
				map[(*iter)->getY()][(*iter)->getX()] = "[*]";
			}
		}
	} // End of for loop (place game characters position on map)

	for (int i = 0; i < mapSize; i++)
	{
		for (int j = 0; j < mapSize; j++)
		{
			if (j == 9) {
				cout << map[i][j] << endl;
			}
			else {
				cout << map[i][j];
			}
		} // End of for loop (y coordinates)
	} // End of for loop (x coordinates)

	weather++; // Increment weather integer by 1

	cout << endl; // Used for spacing in the compiler
} // End of printMap function

// Checks whether the win condition (1 character remianing) has been met
bool Game::checkWin() {
	int count = 0; // Integer used to count number of game characters remaining in iterator
	list<GameCharacter*>::const_iterator iter;

	for (iter = lpGameCharacters.begin(); iter != lpGameCharacters.end();) {
		count++; // Increments counter for number of game characters by 1
		iter++;
	} // End of for loop (number of characters remaining in iterator)


	if (count == 1) {
		// If one game character remains
		return true;
	}
	else {
		// If more than one game character remains
		return false;
	}
} // End of checkWin function

// Displays a win message depending on whether player or enemy won the game
void Game::win() {
	list<GameCharacter*>::const_iterator iter;

	for (iter = lpGameCharacters.begin(); iter != lpGameCharacters.end(); iter++) {
		if ((*iter)->getID() == "p1") {
			// PLayer wins
			cout << "With steel and valor, you have vanquished all who stood in your path. "
			"The kingdom is restored, and your name shall be sung in legend for generations "
			"to come!" << endl;
		}
		else {
			// Enemies win
			cout << "Your blade lies broken, your banner fallen. The kingdom is lost to "
			"darkness, and your name fades into oblivion. Who will rise to finish what you "
			"could not?" << endl;
		}
	}
} // End of win function