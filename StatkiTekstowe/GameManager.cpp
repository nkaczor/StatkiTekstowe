#include "GameManager.h"
#include <stddef.h>
#include <iostream>
#include "AIPlayer.h"
using namespace std;
GameManager* GameManager::_instance=NULL;
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
	cout << "Witaj w grze w statki :) Podaj swoje imie aby rozpoczac gre"<<endl;
	cin >> name;
	Player *you = new Player(name);
	AIPlayer *computer = new AIPlayer();
	while (you->IsAlive() && computer->IsAlive()){
		you->MakeMove(computer);
		if (computer->IsAlive() == false) break;
		computer->MakeMove(you);
	
	}

}
GameManager::~GameManager()
{
}
