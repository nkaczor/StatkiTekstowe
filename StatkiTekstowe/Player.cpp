#include "Player.h"


Player::Player(string name)
{
	this->numberOfShips = 0;
}

void Player::setShips(){
	
	setShip(3);
	setShip(3);
	setShip(2);
	setShip(4);
	setShip(5);
	setShip(6);

}
void Player::setShip(int size){
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
Player::~Player()
{
}
