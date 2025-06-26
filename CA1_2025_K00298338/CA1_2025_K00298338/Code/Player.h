#pragma once
#include "GameCharacter.h"

class Player : public GameCharacter {
private:

public:
	Player(); // Non-paramaterised constructor
	void update(); // Updates the players location based on the users chosen direction
};
