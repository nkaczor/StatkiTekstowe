#include "Player.h"
#include <iostream>
using namespace std;

Player::Player()
{

}
Player::Player(string name)
{
	this->name = name;
	this->numberOfShips = 0;
	setShips();
	cout << "Twoja plansza wyglada tak:" <<  endl;
	Board.ShowBoard();
	
}

bool Player::IsAlive(){
	if (Board.NumberOfAliveShips > 0)
		return true;
	return false;

}
void Player::MakeMove(Player *opponent){
		int x, y;
		cout <<name<< ", podaj wspolrzedne celu x <1,10>, y <1,10>" << endl;
		cin >> x >> y;
		while (x < 1 || x>10 || y < 1 || y>10){
			cout << "Z tymi danymi jest cos nie tak. Podaj jeszcze raz x i y" << endl;
			cin >> x >> y;
		}
		while (!opponent->Board.IsHidden(x - 1, y - 1)){
			cout << "To pole zosta³o ju¿ odkryte. Jego stan to: " << opponent->Board.StateToString(x-1, y-1) << endl;
			cout << "Podaj nowe wspolrzedne" << endl;
			cin >> x >> y;
			while (x < 1 || x>10 || y < 1 || y>10){
				cout << "Z tymi danymi jest cos nie tak. Podaj jeszcze raz x i y" << endl;
				cin >> x >> y;
			}
		}
		x--; y--;

		opponent->Board.OnShot(x, y);


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
	char choice;
	int x, y;
	Ship* newShip = NULL;
	list <pair<int, int>*> squares;
	cout <<name<<", jak chcesz ustawic swoj statek o rozmiarze " << size << endl;
	cout << "wpisz v dla pionowo" << endl;
	cout << "wpisz h dla poziomo" << endl;
	cin >> choice;
	while (choice != 'v' && choice != 'h'){
		cout << "Wpisales niepoprawna komende. Sprobuj jeszcze raz" << endl;
		cin >> choice;
	}
	
	if (choice == 'h'){

		cout << "Podaj wspolrzedne pierwszego elementu dla tego statku x <1," << 11 - size << ">, y <1,10>" << endl;
		cin >> x >> y;
		while (x < 1 || x>11 - size || y < 1 || y>10){
			cout << "Z tymi danymi jest cos nie tak. Podaj jeszcze raz x i y" << endl;
			cin >> x >> y;
		}
		x--; y--;
		bool state = true;
		
		for (int i = 0; i < size; i++)
			if (!Board.IsSquareFree(x + i, y)){ state = false; squares.clear(); }
			else squares.push_back(new pair<int, int>(x + i, y));

			while (state == false){
				cout << "Niestety w tym miejscu nie mozna ustawic tego statku." << endl;
				cout << "Podaj nowe wspolrzedne" << endl; //TODO walidacja
				cin >> x >> y;
				state = true;
				x--; y--;
				for (int i = 0; i < size; i++)
					if (!Board.IsSquareFree(x + i, y)){ state = false; squares.clear(); break; }
					else squares.push_back(new pair<int, int>(x + i, y));
			}
			
	}
	else  {
		cout << "Podaj wspolrzedne pierwszego elementu dla tego statku x <1,10>, y <1, " << 11 - size << ">" << endl;
		cin >> x >> y;
		while (x < 1 || x>10 || y < 1 || y>11 - size){
			cout << "Z tymi danymi jest cos nie tak. Podaj jeszcze raz x i y" << endl;
			cin >> x >> y;
		}
		x--; y--;
		bool state = true;
		
		for (int i = 0; i < size; i++)
			if (!Board.IsSquareFree(x, y + i)){ state = false; squares.clear(); break; }
			else squares.push_back(new pair<int, int>(x, y + i));

			while (state == false){
				cout << "Niestety w tym miejscu nie mozna ustawic tego statku." << endl;
				cout << "Podaj nowe wspolrzedne" << endl; //TODO walidacja
				cin >> x >> y;

				state = true;
				x--; y--;
				for (int i = 0; i < size; i++)
					if (!Board.IsSquareFree(x, y + i)){ state = false; squares.clear(); }
					else squares.push_back(new pair<int, int>(x, y + i));
			}
			

	}
	newShip = new Ship(size);
	Board.SetSquares(squares, newShip);
	listOfShips.push_back(*newShip);
	numberOfShips++;
}
Player::~Player()
{
}
