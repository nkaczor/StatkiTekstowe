#include "AIPlayer.h"


AIPlayer::AIPlayer() : Player("Computer")
{
	setShips();
}

void AIPlayer::setShips(){
	setShip(3);
	setShip(3);
	setShip(4);
	setShip(4);
	setShip(4);
	setShip(5);
	setShip(5);
}
void AIPlayer::setShip(int size){
	int x, y;
	do
	{
		x = rand() % 16;
		y = rand() % 16;
	}
	while (board.IsSquareFree(x, y));

	while (board.NewShipOrNull(x,y)==NULL)
	{

	}




}
AIPlayer::~AIPlayer()
{
}
