#pragma once
#include "Square.h"
#include "Board.h"
#include "Ship.h"
class Board
{
public:
	Board();
	~Board();
	bool IsSquareFree(int x, int y);
	Ship* NewShipOrNull(int x, int y, int size);
	void ShowBoard();
private:
	Square squaresTable[10][10];
	void setSquares(list <pair<int, int>*> squares);
};

