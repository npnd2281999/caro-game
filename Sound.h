#ifndef _Sound_h
#define _Sound_h

#include <iostream>
#include <Windows.h>
#include <string>

#pragma comment(lib, "winmm.lib")

using namespace std;

class Sound
{
public:
	static void playSound(string);
	static void setVolume(int);
	static void moveSound();
};

#endif