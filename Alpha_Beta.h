#ifndef _Alpha_Beta_h
#define _Alpha_Beta_h

#include "Board.h"
#include "Game.h"
#include <string>
#include <fstream>

class AlphaBeta: public Game
{
public:
	COORD minimax(int, int, bool);
	int BestScoreState(int, int);
	int ScoreState(int, int);
	int Min(int a[], int n);
	int Max(int a[], int n);
	void getCmpState(string cmp[], int Score[]);
};

#endif