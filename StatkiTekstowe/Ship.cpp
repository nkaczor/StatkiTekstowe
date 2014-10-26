#include "Ship.h"


Ship::Ship(int size)
{
	this->size = size;
	this->untouchedSquares = size;
}
bool Ship::IsAlive(){
	if (untouchedSquares > 0) return true;
	return false;
}
void Ship::OnShot(){
	untouchedSquares--;

}

Ship::~Ship()
{
}
