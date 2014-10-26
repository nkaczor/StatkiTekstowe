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
bool Square::IsOccupied(){
	return this->occupied;

}
int Square::Shot(){
	this->hidden = false;
	if (this->occupied) {
		this->ship->OnShot();
		if (!this->ship->IsAlive()) { cout << "ZATOPIONY!" << endl; return 1; }
		return 0;
	}
	else return -1;
}
bool Square::IsHidden(){
	return this->hidden;

}
string Square::StateToString(){
	if (this->hidden) return "nieodkryte \n";
	else if (this->occupied) return "odkryte, zestrzelone \n";
	else return "odkryte, pudlo \n";
}
Square::~Square()
{
}
