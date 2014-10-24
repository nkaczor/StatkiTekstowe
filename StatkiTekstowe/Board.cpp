#include "Board.h"
#include <list>


Board::Board()
{
}

bool Board::IsSquareFree(int x, int y){
	if (!squaresTable[x][y].isEmpty()) return 0;
	else if (x>0 && !squaresTable[x-1][y].isEmpty()) return 0;
	else if (y>0 && !squaresTable[x][y-1].isEmpty()) return 0;
	else if (y>0 && x>0 && !squaresTable[x-1][y - 1].isEmpty()) return 0;
	else if (y<15 && !squaresTable[x][y + 1].isEmpty()) return 0;
	else if (x<15 && !squaresTable[x+1][y].isEmpty()) return 0;
	else if (y<15 && x<15 && !squaresTable[x + 1][y + 1].isEmpty()) return 0;
	else if (y<15 && x>0 && !squaresTable[x - 1][y + 1].isEmpty()) return 0;
	else if (y>0 && x<15 && !squaresTable[x + 1][y - 1].isEmpty()) return 0;
	return true;
}
Ship* Board::NewShipOrNull(int x, int y, int size){
	list <pair<int, int>> squares;
	if (x + size <= 16){
	
	
	}
	else if (x - size + 1 >= 0){
	
	
	}
	else if (y + 1 - size >= 0){
	
	}
	else if (y + size <= 16){
	
	
	}

}
Board::~Board()
{
}
