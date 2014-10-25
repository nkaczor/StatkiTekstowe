#include "Player.h"
#include <iostream>
using namespace std;

Player::Player()
{

}
Player::Player(string name)
{
	this->numberOfShips = 0;
	setShips();
	cout << "Twoja plansza wyglada tak:" <<  endl;
	board.ShowBoard();
	numberOfAliveShips = numberOfShips;
}
bool Player::IsAlive(){
	if (numberOfAliveShips > 0) return true;
	else return false;

}
void Player::MakeMove(Player *opponent){
		int x, y;
		cout << "Podaj wspolrzedne celu x <1,10>, y <1,10>" << endl;
		cin >> x >> y;
		while (x < 1 || x>10 || y < 1 || y>10){
			cout << "Z tymi danymi jest cos nie tak. Podaj jeszcze raz x i y" << endl;
			cin >> x >> y;
		}
		while (!opponent->board.IsHidden(x - 1, y - 1)){
			cout << "To pole zosta³o ju¿ odkryte. Jego stan to: " << opponent->board.StateToString(x-1, y-1) << endl;
			cout << "Podaj nowe wspolrzedne" << endl;
			cin >> x >> y;
			while (x < 1 || x>10 || y < 1 || y>10){
				cout << "Z tymi danymi jest cos nie tak. Podaj jeszcze raz x i y" << endl;
				cin >> x >> y;
			}
		}
		x--; y--;

		cout<<opponent->board.OnShot(x, y);


}
void Player::setShips(){

	setShip(3);
	setShip(3);
	/*setShip(2);
	setShip(4);
	setShip(5);
	setShip(6);*/

}
void Player::setShip(int size){
	char choice;
	int x, y;
	Ship* newShip = NULL;
	cout << "Jak chcesz ustawic swoj statek o rozmiarze " << size << endl;
	cout << "wpisz v dla pionowo" << endl;
	cout << "wpisz h dla poziomo" << endl;
	cin >> choice;
	while (choice != 'v' && choice != 'h'){
		cout << "Wpisales niepoprawna komende. Sprobuj jeszcze raz" << endl;
		cin >> choice;
	}
	if (choice == 'v'){

		cout << "Podaj wspolrzedne pierwszego elementu dla tego statku x <1," << 11 - size << ">, y <1,10>" << endl;
		cin >> x >> y;
		while (x < 1 || x>11 - size || y < 1 || y>10){
			cout << "Z tymi danymi jest cos nie tak. Podaj jeszcze raz x i y" << endl;
			cin >> x >> y;
		}
		x--; y--;
		bool state = true;
		list <pair<int, int>*> squares;
		for (int i = 0; i < size; i++)
			if (!board.IsSquareFree(x + i, y)){ state = false; squares.clear(); }
			else squares.push_back(new pair<int, int>(x + i, y));

			while (state == false){
				cout << "Niestety w tym miejscu nie mozna ustawic tego statku." << endl;
				cout << "Podaj nowe wspolrzedne" << endl; //TODO walidacja
				cin >> x >> y;
				state = true;
				x--; y--;
				for (int i = 0; i < size; i++)
					if (!board.IsSquareFree(x + i, y)){ state = false; squares.clear(); }
					else squares.push_back(new pair<int, int>(x + i, y));
			}
			newShip = new Ship(size);
			board.SetSquares(squares, newShip);
			this->listOfShips.push_back(*newShip);
			this->numberOfShips++;
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
		list <pair<int, int>*> squares;
		for (int i = 0; i < size; i++)
			if (!board.IsSquareFree(x, y + i)){ state = false; squares.clear(); break; }
			else squares.push_back(new pair<int, int>(x, y + i));

			while (state == false){
				cout << "Niestety w tym miejscu nie mozna ustawic tego statku." << endl;
				cout << "Podaj nowe wspolrzedne" << endl; //TODO walidacja
				cin >> x >> y;

				state = true;
				x--; y--;
				for (int i = 0; i < size; i++)
					if (!board.IsSquareFree(x, y + i)){ state = false; squares.clear(); }
					else squares.push_back(new pair<int, int>(x, y + i));
			}
			newShip = new Ship(size);
			board.SetSquares(squares,newShip);
			this->listOfShips.push_back(*newShip);
			this->numberOfShips++;

	}
}
Player::~Player()
{
}
