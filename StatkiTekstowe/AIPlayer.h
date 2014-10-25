#pragma once
#include "Player.h"
class AIPlayer : public Player
{
public:
	AIPlayer();
	~AIPlayer();
	void MakeMove(Player *opponent);
private:
	
	void setShip(int size);
	bool haveTarget;
};

