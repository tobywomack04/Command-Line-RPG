#pragma once
#include <string>

using namespace std;

class GameCharacter {

private:

protected:
	string m_typeID; // The ID of each character in the game
	double m_health; // Health value between (player: 140 & 170) & (enemy: 90 & 150)
	int m_speed; // Speed value between (player: 2 & 4) & (enemy: 1 & 3)
	int m_x; // X coordinate Between 1 & 10
	int m_y; // Y coordinate Between 1 & 10
	int m_maxHp; // The maximum health value that the player can heal to
	int m_potionCount; // Number of healing potions the game character has

public:
	GameCharacter();
	void spawn(std::string typeID, double health, int speed, int x, int y, int potionCount); // Create an object
	void render(); // Displays the ID, x cord and y cord of each game character
	virtual void update() = 0; // Virtual function
	void stats(); // Print all stats relating to the object
	bool isAlive(); // Return true if its health is greater than 0
	int getX(); // Returns the x coordinate
	int getY(); // Returns the y coordintate
	double getHP(); // Returns the health value
	void setHP(double hp); // Sets the health value
	string getID(); // Returns the creature ID
	void heal(double amount); // Character chooses to heal for 10% HEALTH
	void setPotionCount(int count); // Sets the number of healing potions avaliable to the game character
	int getPotionCount(); // Returns the number of healing potions avaliable to the game character
	int getMaxHp(); // Returns the maximum health value of the game character
};