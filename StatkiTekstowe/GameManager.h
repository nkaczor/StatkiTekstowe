#pragma once
class GameManager
{
private:
	GameManager();
	~GameManager();
	static GameManager* _instance;
public: 
	static GameManager *GetGameManager();
	void PrepareGame();
	
	
};

