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
//	game->StartGame();
	//game->ShowResults();


	system("pause");

	return 0;
}

