#pragma once

#include "Square.h"
using namespace std;
class Ship
{
public:
	Ship();
	~Ship();
	bool isAlive();
private:
	bool alive;
	int size;
	Square *listOfSquares;
};

