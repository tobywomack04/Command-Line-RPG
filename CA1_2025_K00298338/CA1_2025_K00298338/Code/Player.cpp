#include <iostream>
#include "Player.h"

using namespace std;

// Non-paramaterised constructor
Player::Player() {
	
}

// Updates the players location based on the users chosen direction
void Player::update() {
	char direction = 'A'; // Character used to store selected direction
	bool dirChosen = false; // Boolean used to check whether a valid direction has been chosen

	cout << "In which direction would you care to move? (N, E, S, W)" << endl;
	cout << "N: North" << endl;
	cout << "E: East" << endl;
	cout << "S: South" << endl;
	cout << "W: West" << endl;
	
	cin >> direction; // Takes in directional input
	direction = toupper(direction); // Converts input to uppercase character for switch statement

	do {
		switch (direction)
		{
			// Chooses to move north
			case 'N':
				dirChosen = true;
				m_y -= 1;

				if (m_y == -1) {
					m_health -= (m_speed * 2);
					m_y += 1;
				}
				break;

			// Chooses to move east
			case 'E':
				dirChosen = true;
				m_x += 1;

				if (m_x == 10) {
					m_health -= (m_speed * 2);
					m_x -= 1;
				}
				break;

			// Chooses to move south
			case 'S':
				dirChosen = true;
				m_y += 1;

				if (m_y == 10) {
					m_health -= (m_speed * 2);
					m_y -= 1;
				}
				break;

			// Chooses to move west
			case 'W':
				dirChosen = true;
				m_x -= 1;

				if (m_x == -1) {
					m_health -= (m_speed * 2);
					m_x += 1;
				}
				break;

			// Didn't enter a valid direction
			default:
				cout << "Error: please enter the direction again" << endl;
				cin >> direction; // Takes in directional input
				direction = toupper(direction); // Converts input to uppercase character
				break;
		}
	} while (dirChosen != true);

	cout << endl; // Used for spacing in the compiler
} // End of update function