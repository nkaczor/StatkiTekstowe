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
	vector <pair<int,int>*> unfinishedTarget;
	void setShip(int size);
	bool haveTarget;
	pair<int, int>* checkNeighbors(int x, int y);
	char alignmentOfTarget; //'u' unknown
};

