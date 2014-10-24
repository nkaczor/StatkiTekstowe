#pragma once
#include "Square.h"
class Board
{
public:
	Board();
	~Board();
	
private:
	Square squaresTable[15][15];
};

