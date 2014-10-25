#pragma once
#include "Player.h"
class Square
{
public:
	Square();
	~Square();
	bool isEmpty();
	bool isFinished();
	void MarkAsOccupied();
private:
	int state;
	bool occupied;
	//Player* owner;
};

