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
	cout << "Witaj w grze w statki :) Podaj swoje imiê aby rozpocz¹æ grê";
	Player *you = new Player(name);
	AIPlayer *computer = new AIPlayer();

}
GameManager::~GameManager()
{
}
