#include "GameManager.h"
#include <stddef.h>
#include <iostream>
#include "AIPlayer.h"
using namespace std;
GameManager* GameManager::_instance = NULL;
GameManager::GameManager()
{

}

GameManager* GameManager::GetGameManager()
{
	if (!_instance)
		_instance = new GameManager();
	return _instance;
}

void GameManager::PrepareGame(){
	string name;
	cout << "Witaj w grze w statki :) Podaj swoje imie aby rozpoczac gre" << endl;
	cin >> name;
	you = new Player(name);
	computer = new AIPlayer();

}
void GameManager::StartGame(){
	while (you->IsAlive() && computer->IsAlive()){
		you->MakeMove(computer);
		if (computer->IsAlive() == false) break;
		cout << endl << "Czas na ruch komputera:" << endl;
		computer->MakeMove(you);
		cout << endl;
	}

}
void GameManager::ShowResults(){
	if (computer->IsAlive()) cout << "Przykro mi. Komputer pokonal Cie swoja sztuczna inteligencja" << endl;
	else cout << "Brawo pokonales Komputer!" << endl;

	dispose();
}
void GameManager::dispose(){
	delete you;
	delete computer;
}
GameManager::~GameManager()
{
}
