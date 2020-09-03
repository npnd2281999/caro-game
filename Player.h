#ifndef _PLAYER_H
#define _PLAYER_H
#include"Common.h"
#include <string>

typedef class Player
{
private:
	int move;
	int numWin;
public:
	Player();
	Player(const Player&);
	void drawInfo(string, int, int);
	int getMove();
	void IncreaseMove();
	int getnumWin();
	void IncreaseWin();
	void SetMove(const int);
} P;

#endif