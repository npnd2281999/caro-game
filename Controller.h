#ifndef _Controller_h
#define _Controller_h

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include "Common.h"
#include <string>
#include "Sound.h"


using namespace std;

class Controller
{
public:
	static int move();
	static void setTextColor(int);
	static string setMusic();
	static int setVolume();
	static void Delete(int , int , int );
	static int setSize();
	static int setLeft();
	static int setTop();
};

#endif _Controller_h