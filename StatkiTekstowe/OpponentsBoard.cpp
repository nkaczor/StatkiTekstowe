#include "OpponentsBoard.h"
#include <string>
using namespace std;
OpponentsBoard::OpponentsBoard()
{	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			squaresTable[i][j] = 'u';
		}
	}
	
}
string OpponentsBoard::StateToString(int x, int y){
	if (squaresTable[x][y] == 'u') return "nieodkryte";
	if (squaresTable[x][y] == 'd') return "odkryte, zestrzelone";
	if (squaresTable[x][y] == 'm') return "odkryte, pud³o";
}
bool OpponentsBoard::IsHidden(int x, int y){
	if (squaresTable[x][y] == 'u') return true;
	return false;
}
OpponentsBoard::~OpponentsBoard()
{
}
