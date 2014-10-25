#pragma once
class OpponentsBoard
{
public:
	OpponentsBoard();
	~OpponentsBoard();
	bool IsHidden(int x, int y);
	string StateToString(int x, int y);
private:
	char squaresTable[10][10];
};

