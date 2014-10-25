#pragma once
#include "Player.h"
class AIPlayer : public Player
{
public:
	AIPlayer();
	~AIPlayer();
	
private:
	
	void setShip(int size);
};

