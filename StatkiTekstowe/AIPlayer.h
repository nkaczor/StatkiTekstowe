#pragma once
#include "Player.h"
class AIPlayer : Player
{
public:
	AIPlayer();
	~AIPlayer();
	
private:
	void setShips();
	void setShip(int size);
};

