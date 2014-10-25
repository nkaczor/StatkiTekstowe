#include "AIPlayer.h"
#include <iostream>
using namespace std;


AIPlayer::AIPlayer() 
{
	name = "Computer";
	setShips();
	this->haveTarget = false;
	//board.ShowBoard(); //tylko do celow diagnostycznych
	
}

void AIPlayer::MakeMove(Player *opponent){
	int x, y;
	if (!haveTarget) {
		
			do{
				x = rand() % 10;
				y = rand() % 10;
			} while (!opponent->board.IsHidden(x,y));
	

	}
	if (opponent->board.OnShot(x, y)) this->haveTarget = true;

}
void AIPlayer::setShip(int size){
	int x, y;
	Ship* newShip = NULL;
	do{
		do{
			x = rand() % 10;
			y = rand() % 10;
		} while (!board.IsSquareFree(x, y));

	} while ((newShip = board.NewShipOrNull(x, y, size)) == NULL);


	this->listOfShips.push_back(*newShip);
	this->numberOfShips++;


}
AIPlayer::~AIPlayer()
{
}
