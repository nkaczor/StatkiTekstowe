#pragma once

#include "Square.h"
#include <list>
using namespace std;
class Ship
{
public:
	Ship(list <pair<int, int>*> squares);
	~Ship();
	bool isAlive();
private:
	bool alive;
	int size;
	list<Square> listOfSquares;
};

