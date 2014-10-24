#include "Board.h"
#include <list>


Board::Board()
{
}

bool Board::IsSquareFree(int x, int y){
	if (!squaresTable[x][y].isEmpty()) return 0;
	else if (x > 0 && !squaresTable[x - 1][y].isEmpty()) return 0;
	else if (y > 0 && !squaresTable[x][y - 1].isEmpty()) return 0;
	else if (y > 0 && x > 0 && !squaresTable[x - 1][y - 1].isEmpty()) return 0;
	else if (y < 15 && !squaresTable[x][y + 1].isEmpty()) return 0;
	else if (x < 15 && !squaresTable[x + 1][y].isEmpty()) return 0;
	else if (y < 15 && x < 15 && !squaresTable[x + 1][y + 1].isEmpty()) return 0;
	else if (y < 15 && x>0 && !squaresTable[x - 1][y + 1].isEmpty()) return 0;
	else if (y>0 && x < 15 && !squaresTable[x + 1][y - 1].isEmpty()) return 0;
	return true;
}
void Board::setSqueres(list <pair<int, int>*> squares){

//TODO
}
Ship* Board::NewShipOrNull(int x, int y, int size){
	list <pair<int, int>*> squares;
	bool state = true;
	if (x + size <= 16){
		for (int i = 0; i < size; i++)
			if (!IsSquareFree(x + i, y)){ squares.clear(); state = false;  break; }
			else squares.push_back(new pair<int, int>(x + i, y));
			if (state) { setSqueres(squers);  return new Ship(squares); }
	}
	if (x - size + 1 >= 0){
		for (int i = 0; i < size; i++)
			if (!IsSquareFree(x - i, y)){ squares.clear(); state = false;  break; }
			else squares.push_back(new pair<int, int>(x - i, y));
			if (state) { setSqueres(squers); return new Ship(squares); }

	}
	if (y + 1 - size >= 0){
		for (int i = 0; i < size; i++)
			if (!IsSquareFree(x, y-i)){ squares.clear(); state = false;  break; }
			else squares.push_back(new pair<int, int>(x, y-i));
			if (state) { setSqueres(squers); return new Ship(squares); }
	}
	if (y + size <= 16){
		for (int i = 0; i < size; i++)
			if (!IsSquareFree(x , y+i)){ squares.clear(); state = false;  break; }
			else squares.push_back(new pair<int, int>(x, y+i));
			if (state) { setSqueres(squers); return new Ship(squares); }

	}
	return NULL;
}
Board::~Board()
{
}
