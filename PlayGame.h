#ifndef _PlayGame_h
#define _PlayGame_h

#include "Game.h"
#include <time.h>
#include <stdlib.h>
#include "Alpha_Beta.h"

static int BOARD_SIZE = 15;
static int LEFT = 50;
static int TOP = 4;


class PlayGame
{
public:
	static void PvP(Game);
	static void PvCRandom(Game);
	static void PvAI(Game);
};

#endif