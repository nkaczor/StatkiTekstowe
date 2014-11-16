#pragma once
#include <string>
#include "Ship.h"
using namespace std;
class Square
{
public:
	Square();
	~Square();
	bool IsEmpty();
	bool IsOccupied();
	bool IsHidden();
	
	
	friend class Board;
	
private:
	void MarkAsOccupied(Ship * ship);
	string StateToString();
	int Shot();
	bool hidden;
	bool occupied;
	Ship* ship;
};

