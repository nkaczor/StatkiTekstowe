#pragma once
#include "Player.h"
class AIPlayer : public Player
{
public:
	AIPlayer();
	~AIPlayer();
	void MakeMove(Player *opponent);
private:
	bool targetTable[10][10];
	list <pair<int,int>*> unfinishedTarget;
	void setShip(int size);
	bool haveTarget;
	bool checkNeighbors(int x, int y)
};

