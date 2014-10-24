#pragma once
class Square
{
public:
	Square();
	~Square();
	bool isEmpty();
	bool isFinished();
private:
	int state;
	Player *owner;
};

