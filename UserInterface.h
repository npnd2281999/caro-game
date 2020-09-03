#ifndef _UserInterface_h
#define _UserInterface_h

#include "Controller.h"
#include <fstream>
#include <iostream>

class UserInterface
{
public:
	void Load();
	int gameMenu();
	void settingMenu(string&, int&);
	int playGameMenu();
	int difficulty();
	static void Result(string);
	static void gameName(int);
};

#endif