#pragma once
#include <string>
#include <vector>
#include "Ship.h"
#include "Board.h"
using namespace std;
class Player
{
public:
	Player(string name);
	~Player();
	void AddShip(Ship ship);
	bool IsEnableToPlay();
protected:
	void setShips();
	virtual void setShip(int size);
	string name;
	int numberOfShips;
	int numberOfAliveShips;
	vector <Ship> listOfShips;
	Board board;
};

