#ifndef _Common_h
#define _Common_h

#include <iostream>
#include <Windows.h>

using namespace std;

class Common
{
public:
	static void fixConsoleWindow();
	static void gotoXY(int, int);
	static void hideCursor(bool);
	static void removeScrollbar();
	static void setSize();
};

#endif