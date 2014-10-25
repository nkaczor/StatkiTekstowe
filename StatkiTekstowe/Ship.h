#pragma once


#include <list>
using namespace std;
class Ship
{
public:
	Ship(int size);
	~Ship();
	bool IsAlive();
	void OnShot();
private:
	
	int size;
	int untouchedSquares;
	
};

