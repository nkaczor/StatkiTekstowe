#include "Board.h"
#include <list>
#include <iostream>
using namespace std;

Board::Board()
{
	NumberOfAliveShips = 0;

}

int Board::OnShot(int x, int y){ //-1 pudlo 0 trafiony 1 trafiony zatopiony
	
	int result= squaresTable[x][y].Shot();
	
	cout << "Strzal na " << x + 1 << " " << y + 1 << endl;
	cout << squaresTable[x][y].StateToString();
	if (result == 1) {
		NumberOfAliveShips--;
		cout << "I TO BYL STRZAL OSTATECZNY - ZATOPIONY!" << endl;
	}
	
	
	return result;
}
void Board::ShowBoard(){
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++)
		{
			cout << squaresTable[j][i].IsEmpty() << " ";
		}
		cout << endl;
	}
	cout << endl;
}
string Board::MakeString(){
	string result;
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++)
		{
			if(squaresTable[j][i].IsEmpty()) result=result+"O ";
			else  result = result + "X ";
		}
		result = result + "\n";
	}
	return result;
}

ostream & operator<< (ostream &wyjscie,Board &s) {
	
	return wyjscie <<  s.MakeString();
}
bool Board::IsHidden(int x, int y){
	return squaresTable[x][y].IsHidden();

}
string Board::StateToString(int x, int y){
	return squaresTable[x][y].StateToString();

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
void Board::SetSquares(list <pair<int, int>*> squares, Ship *ship){
	  list<pair<int, int>*>::iterator it;
   for( it=squares.begin(); it!=squares.end(); ++it )
   {
		squaresTable[(*it)->first][(*it)->second].MarkAsOccupied(ship);

	}
	NumberOfAliveShips++;

}
Ship* Board::NewShipOrNull(int x, int y, int size){
	list <pair<int, int>*> squares;
	bool state = true;
	Ship* newShip;
	if (x + size <= 10){
		for (int i = 0; i < size; i++)
			if (!IsSquareFree(x + i, y)){ squares.clear(); state = false;  break; }
			else squares.push_back(new pair<int, int>(x + i, y));
			if (state) { newShip = new Ship(size); SetSquares(squares,newShip);  return newShip; }
	}
	
	if (y + 1 - size >= 0){
		for (int i = 0; i < size; i++)
			if (!IsSquareFree(x, y - i)){ squares.clear(); state = false;  break; }
			else squares.push_back(new pair<int, int>(x, y - i));
			if (state) { newShip = new Ship(size); SetSquares(squares, newShip);  return newShip; }
	}
	if (x - size + 1 >= 0){
		for (int i = 0; i < size; i++)
			if (!IsSquareFree(x - i, y)){ squares.clear(); state = false;  break; }
			else squares.push_back(new pair<int, int>(x - i, y));
			if (state) { newShip = new Ship(size); SetSquares(squares, newShip);  return newShip; }

	}
	if (y + size <= 10){
		for (int i = 0; i < size; i++)
			if (!IsSquareFree(x, y + i)){ squares.clear(); state = false;  break; }
			else squares.push_back(new pair<int, int>(x, y + i));
			if (state) { newShip = new Ship(size); SetSquares(squares, newShip);  return newShip; }

	}
	return NULL;
}
Board::~Board()
{

}
