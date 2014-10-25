#include "AIPlayer.h"


AIPlayer::AIPlayer() : Player("Computer")
{
	setShips();
	//board.ShowBoard(); //tylko do celow diagnostycznych
	numberOfAliveShips = numberOfShips;
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
