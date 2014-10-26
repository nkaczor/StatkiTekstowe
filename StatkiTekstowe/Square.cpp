#include "Square.h"
#include <iostream>
using namespace std;

Square::Square()
{
	this->occupied = false;
	this->hidden = true;
}

void Square::MarkAsOccupied(Ship *ship){
	occupied = true;
	this->ship = ship;

}
bool Square::IsEmpty(){
	return !occupied;

}
bool Square::IsOccupied(){
	return occupied;

}
int Square::Shot(){
	hidden = false;
	if (occupied) {
		ship->OnShot();
		if (!ship->IsAlive()) { cout << "ZATOPIONY!" << endl; return 1; }
		return 0;
	}
	else return -1;
}
bool Square::IsHidden(){
	return hidden;

}
string Square::StateToString(){
	if (hidden) return "nieodkryte \n";
	else if (occupied) return "odkryte, zestrzelone \n";
	else return "odkryte, pudlo \n";
}
Square::~Square()
{
}
