#include "GameCharacter.h"
#include <iostream>

using namespace std;

// Non-paramaterised constructor
GameCharacter::GameCharacter() {
	
}

// Parameterised constructor (ID, health, speed, x cord, y cord, number of healing potions)
void GameCharacter::spawn(string typeID, double health, int speed, int x, int y, int potionCount) {
	m_typeID = typeID;
	m_health = health;
	m_speed = speed;
	m_x = x;
	m_y = y;
	m_maxHp = health;
	m_potionCount = potionCount;
}

// Prints ID, X coordinate and Y coordinate of each game character
void GameCharacter::render() {
	cout << "ID: " << m_typeID << " | X cord: " << m_x << " | Y cord: " << m_y << endl;
}

// Prints ID, health, speed, X coordinate and Y coordinate of each game character
void GameCharacter::stats() {
	cout << "ID: " << m_typeID << " | Health: " << m_health << " | Speed: " << m_speed << " | X cord: " << m_x << " | Y cord: " << m_y << endl;
}

// Checks for whether the game character's health is less than 1
bool GameCharacter::isAlive() {
	if (m_health < 1) {
		return false;
	}
	else {
		return true;
	}
}

// Returns X coordinate of game character
int GameCharacter::getX() {
	return m_x;
}

// Returns Y coordinate of game character
int GameCharacter::getY() {
	return m_y;
}

// Returns game character's health value
double GameCharacter::getHP() {
	return m_health;
}

// Sets the game character's health value
void GameCharacter::setHP(double hp) {
	m_health = hp;
}

// Returns the game character's ID
string GameCharacter::getID() {
	return m_typeID;
}

// Heals 10% of the game character's health
void GameCharacter::heal(double amount) {

	if ((m_health + amount) > m_maxHp) {
		cout << "Even the strongest elixirs cannot mend what is already whole" << endl;
	}
	else {
		m_health += amount;
		m_potionCount--;
		cout << "You have restored 10% of your strength, but the road ahead remains perilous" << endl;
	}
}

// Sets the number of potions the game character has
void GameCharacter::setPotionCount(int count) {
	m_potionCount = count;
}

// Returns the number of potions the game character has
int GameCharacter::getPotionCount() {
	return m_potionCount;
}

int GameCharacter::getMaxHp() {
	return m_maxHp;
}