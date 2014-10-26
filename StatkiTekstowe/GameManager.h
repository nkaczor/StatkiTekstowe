#pragma once
#include "AIPlayer.h"
class GameManager
{
private:
	GameManager();
	~GameManager();
	Player *you;
	AIPlayer *computer;
	static GameManager* _instance;
	void dispose();
public: 
	static GameManager *GetGameManager();
	void PrepareGame();
	void StartGame();
	void ShowResults();
	
	
};

