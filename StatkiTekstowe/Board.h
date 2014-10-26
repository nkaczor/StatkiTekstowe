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
	void SetSquares(list <pair<int, int>*> squares, Ship* ship);
	bool IsHidden(int x, int y);
	string StateToString(int x, int y);
	int OnShot(int x, int y);
	int NumberOfAliveShips;
private:
	Square squaresTable[10][10];
	
	
};

