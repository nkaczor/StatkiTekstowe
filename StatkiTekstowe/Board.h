#pragma once
#include "Square.h"
class Board
{
public:
	Board();
	~Board();
	bool IsSquareFree(int x, int y);
	Ship* NewShipOrNull(int x, int y, int size);
private:
	Square squaresTable[16][16];
};

