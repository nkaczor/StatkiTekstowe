#include "Square.h"
#include <iostream>
using namespace std;

Square::Square()
{
	this->occupied = false;
	this->hidden = true;
}

void Square::MarkAsOccupied(Ship *ship){
	this->occupied = true;
	this->ship = ship;

}
bool Square::IsEmpty(){
	return !this->occupied;

}
void Square::Shot(){
	this->hidden = false;
	if (this->occupied) {
		this->ship->OnShot();
		if (!this->ship->IsAlive()) cout << "ZATOPIONY!" << endl;
	}
}
bool Square::IsHidden(){
	return this->hidden;

}
string Square::StateToString(){
	if (this->hidden) return "nieodkryte";
	else if (this->occupied) return "odkryte, zestrzelone";
	else return "odkryte, pudlo";
}
Square::~Square()
{
}
