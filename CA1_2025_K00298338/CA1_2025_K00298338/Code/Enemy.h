#pragma once
#include "GameCharacter.h"

class Enemy : public GameCharacter {
private:

public:
	Enemy(); // Non-paramaterised constructor
	void update(); // Updates the enemy's position
};
