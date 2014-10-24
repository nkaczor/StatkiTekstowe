#pragma once
#include <string>
#include <list>
#include "Ship.h"
using namespace std;
class Player
{
public:
	Player(string name);
	~Player();
	void AddShip(Ship ship);
private:
	string name;
	list <Ship> listOfShips;
};

