#include "Enemy.h"
#include <iostream>
#include <cstdlib>

// Non-paramaterised constructor
Enemy::Enemy() {
	srand(time(0)); // Seeding randomisers
}

// Updates the enemy's position
void Enemy::update() {

	int move = 1 + rand() % 10; // Random number between 1 & 10 (move or not)

	if (move < 9)
	{
		int upOrDown = 1 + rand() % 2; // Random number between 1 & 2 (up or down)

		if (upOrDown == 1) {
			// Move up
			m_y -= 1;

			// Hits a perimeter
			if (m_y == -1) {
				m_health -= (m_speed * 3);
				m_y += 1;
			}
		}
		else {
			// Move down
			m_y += 1;

			// Hits a perimeter
			if (m_y == 10) {
				m_health -= (m_speed * 3);
				m_y -= 1;
			}
		}
	}
}