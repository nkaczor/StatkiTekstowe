#include "Board.h"
#include <list>
#include <iostream>
using namespace std;

Board::Board()
{


}
void Board::ShowBoard(){
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++)
		{
			cout << this->squaresTable[i][j].IsEmpty() << " ";
		}
		cout << endl;
	}
}
bool Board::IsSquareFree(int x, int y){
	if (!squaresTable[x][y].IsEmpty()) return 0;
	else if (x > 0 && !squaresTable[x - 1][y].IsEmpty()) return 0;
	else if (y > 0 && !squaresTable[x][y - 1].IsEmpty()) return 0;
	else if (y > 0 && x > 0 && !squaresTable[x - 1][y - 1].IsEmpty()) return 0;
	else if (y < 9 && !squaresTable[x][y + 1].IsEmpty()) return 0;
	else if (x < 9 && !squaresTable[x + 1][y].IsEmpty()) return 0;
	else if (y < 9 && x < 9 && !squaresTable[x + 1][y + 1].IsEmpty()) return 0;
	else if (y < 9 && x>0 && !squaresTable[x - 1][y + 1].IsEmpty()) return 0;
	else if (y>0 && x < 9 && !squaresTable[x + 1][y - 1].IsEmpty()) return 0;
	return true;
}
void Board::SetSquares(list <pair<int, int>*> squares){
	for each (pair<int, int>* point in squares)
	{
		this->squaresTable[point->first][point->second].MarkAsOccupied();
	}

}
Ship* Board::NewShipOrNull(int x, int y, int size){
	list <pair<int, int>*> squares;
	bool state = true;
	if (x + size <= 10){
		for (int i = 0; i < size; i++)
			if (!IsSquareFree(x + i, y)){ squares.clear(); state = false;  break; }
			else squares.push_back(new pair<int, int>(x + i, y));
			if (state) { SetSquares(squares);  return new Ship(squares); }
	}
	
	if (y + 1 - size >= 0){
		for (int i = 0; i < size; i++)
			if (!IsSquareFree(x, y - i)){ squares.clear(); state = false;  break; }
			else squares.push_back(new pair<int, int>(x, y - i));
			if (state) { SetSquares(squares); return new Ship(squares); }
	}
	if (x - size + 1 >= 0){
		for (int i = 0; i < size; i++)
			if (!IsSquareFree(x - i, y)){ squares.clear(); state = false;  break; }
			else squares.push_back(new pair<int, int>(x - i, y));
			if (state) { SetSquares(squares); return new Ship(squares); }

	}
	if (y + size <= 10){
		for (int i = 0; i < size; i++)
			if (!IsSquareFree(x, y + i)){ squares.clear(); state = false;  break; }
			else squares.push_back(new pair<int, int>(x, y + i));
			if (state) { SetSquares(squares); return new Ship(squares); }

	}
	return NULL;
}
Board::~Board()
{
}
