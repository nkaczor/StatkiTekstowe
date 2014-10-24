// StatkiTekstowe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "GameManager.h"
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	GameManager *game = GameManager::GetGameManager();
	game->PrepareGame();
	game->StartGame();
	game->ShowResults();
	string name;
	cout << "Witaj graczu! Napisz jak masz na imiê";
	cin >> name;
	cout << "Ustaw swoje statki";

	Player *you = new Player(name);

	getchar();

	return 0;
}

