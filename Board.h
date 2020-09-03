#ifndef _Board_h
#define _Board_h

#include "Point.h"
#include "Controller.h"

class Board
{
private:
	int size;
	int	left, top;
	Point** pArr;
public:
	Board(int, int, int);
	Board(const Board*);
	~Board();
	int getSize();
	int getLeft();
	int getTop();
	int getXAt(int, int);
	int getYAt(int, int);
	void resetData();
	void drawBoard();
	int checkBoard(int, int, bool);
	int checkWin(int, int);
	int testBoard(int, int);
	bool isMatch(int a[]);
	COORD getCOORD(int, int);
	int getCheck(int, int);
	void setCheckAt(int, int, int);
	bool valid(int, int, int, int);
};

#endif