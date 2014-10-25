#pragma once

class Square
{
public:
	Square();
	~Square();
	bool IsEmpty();
	bool IsFinished();
	void MarkAsOccupied();
private:
	int state;
	bool occupied;
	//Player* owner;
};

