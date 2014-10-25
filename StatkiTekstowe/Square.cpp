#include "Square.h"


Square::Square()
{
	this->occupied = false;
}

void Square::MarkAsOccupied(){
	this->occupied = true;

}
bool Square::IsEmpty(){
	return !this->occupied;

}
Square::~Square()
{
}
