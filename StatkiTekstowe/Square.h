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
	bool IsHidden();
	void MarkAsOccupied(Ship * ship);
	string StateToString();
	void Shot();
private:
	bool hidden;
	bool occupied;
	Ship* ship;
};

