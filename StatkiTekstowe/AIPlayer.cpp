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
			} while (targetTable[x][y]);
			targetTable[x][y] = 1;
			if (opponent->board.OnShot(x, y) == 0) { this->haveTarget = true; 
			unfinishedTarget.push_back(new pair<int, int>(x, y));
			}

	}
	else {
		pair<int, int>* k;
		for (list <pair<int, int>*>::iterator it = unfinishedTarget.begin(); it != unfinishedTarget.end(); ++it)
			if (checkNeighbors((*it)->first, ((*it)->second)){}
	
	
	}
	

}
bool AIPlayer::checkNeighbors(int x, int y){
	if (unfinishedTarget.size() == 1){}//nie wiemy czy statek stoi pionowo czy poziomo

	else{}

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
