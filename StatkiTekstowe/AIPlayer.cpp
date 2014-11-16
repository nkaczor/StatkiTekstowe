#include "AIPlayer.h"
#include <iostream>
#include "stdlib.h"
using namespace std;


AIPlayer::AIPlayer()
{
	name = "Computer";
	setShips();
	haveTarget = false;
	//Board.ShowBoard(); //tylko do celow diagnostycznych

}

void AIPlayer::MakeMove(Player *opponent){
	int x, y;
	pair <int, int>* candidate;
	if (!haveTarget) {
		alignmentOfTarget = 'u';
		do{
			x = rand() % 10;
			y = rand() % 10;
		} while (targetTable[x][y]);
		targetTable[x][y] = 1;
		if (opponent->board.OnShot(x, y) == 0) {
			haveTarget = true;
			unfinishedTarget.push_back(new pair<int, int>(x, y));
		}

	}
	else {
		if (unfinishedTarget.size() > 1 && alignmentOfTarget == 'u') {
			if (unfinishedTarget[0]->first == unfinishedTarget[1]->first) alignmentOfTarget = 'v';
			else alignmentOfTarget = 'h';
		}
		
		for (vector <pair<int, int>*>::iterator it = unfinishedTarget.begin(); it != unfinishedTarget.end(); ++it)
			if ( (candidate=checkNeighbors((*it)->first, (*it)->second)) != NULL){
			x = candidate->first;
			y = candidate->second;
			targetTable[x][y] = 1;
			if (opponent->board.OnShot(x, y) == 1) //zestrzelony
			{
				haveTarget = false;
				unfinishedTarget.clear();
			}
			else unfinishedTarget.push_back(new pair<int, int>(x, y));
			break;
			}


	}


}
pair<int, int>* AIPlayer::checkNeighbors(int x, int y){
	if (alignmentOfTarget == 'v' || alignmentOfTarget == 'u'){
		if (y > 0 && targetTable[x][y - 1] == 0)return new pair<int, int>(x, y - 1);
		if (y < 9 && targetTable[x][y + 1] == 0)return new pair<int, int>(x, y + 1);

	}


	if (alignmentOfTarget == 'h' || alignmentOfTarget == 'u'){
		if (x > 0 && targetTable[x - 1][y] == 0)return new pair<int, int>(x - 1, y);
		if (x < 9 && targetTable[x + 1][y] == 0)return new pair<int, int>(x - 1, y);
	}
	return NULL;

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


	listOfShips.push_back(*newShip);
	numberOfShips++;


}
AIPlayer::~AIPlayer()
{
}
