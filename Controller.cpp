#include "Controller.h"
#include "PlayGame.h"

int Controller::move()
{
	char c; //if (_getch() == 13) return 13;;
	c = _getch();
	switch ((int)c)
	{
	case 72:
		return 1;
		break;
	case 80:
		return 2;
		break;
	case 75:
		return 3;
		break;
	case 77:
		return 4;
		break;
	case 13:
		return 13;
	}

}

void Controller::setTextColor(int color)
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, color);
}

string Controller::setMusic()
{
	string music[3]={"ChocoboRacingCidsTestCourse","ChocoboRacingGoblinsTheme",
		"ChocoboRacingRuinsOfTheGiants"};
	int line = 11;
	int key, flag = 0;
	int cur = 0;

	while (1)
	{
		if (_kbhit())
		{
			key = move();
			switch (key)
			{
			case 3:
				cur--;
				if (cur < 0)
					cur = 2;
				break;
			case 4:
				cur++;
				if (cur > 2)
					cur = 0;
				break;
			case 1:
				flag = 1;
				break;
			case 2:
				flag = 1;
				break;
			}
			if (flag)
				break;
			Delete(54, line, 30);
			Common::gotoXY(54, line);
			cout << music[cur];
		}
	}
	if (cur == 0)
		return "ChocoboRacingCidsTestCourse";
	else if (cur == 1)
		return "ChocoboRacingGoblinsTheme";
	else return "ChocoboRacingRuinsOfTheGiants";
}

void Controller::Delete(int x, int y , int length)
{
	Common::gotoXY(x, y);
	for (int i = 0; i < length; i++)
	{
		cout << " ";
	}
	Common::gotoXY(x, y);
}


int Controller::setVolume()
{
	int max = 100, min = 0;
	int line = 12;
	int key; int volume = 50;
	int flag = 0;
	while (1)
	{

		if (_kbhit())
		{
			key = move();
			Common::gotoXY(64,line);
			switch (key)
			{
			case 3:
				volume--;
				if (volume < min)
					volume = max;
				break;
			case 4:
				volume++;
				if (volume > max)
					volume = min;
				break;
			case 1:
				flag = 1;
				break;
			case 2:
				flag = 1;
				break;
			}
			if (flag)
				break;
			Delete(54, line, 8);
			Common::gotoXY(54, line);
			cout << volume;
		}
	}
	return volume;
}

int Controller::setSize()
{
	int max = 50, min = 8;
	int line = 13;
	int key; 
	int flag = 0;
	while (1)
	{

		if (_kbhit())
		{
			key = move();
			Common::gotoXY(64, line);
			switch (key)
			{
			case 3:
				BOARD_SIZE--;
				if (BOARD_SIZE < min)
					BOARD_SIZE = max;
				break;
			case 4:
				BOARD_SIZE++;
				if (BOARD_SIZE > max)
					BOARD_SIZE = min;
				break;
			case 1:
				flag = 1;
				break;
			case 2:
				flag = 1;
				break;
			}
			if (flag)
				break;
			Delete(54, line, 8);
			Common::gotoXY(54, line);
			cout << BOARD_SIZE;
		}
	}
	return BOARD_SIZE;
}

int Controller::setLeft()
{
	int max = 100, min = 0;
	int line = 14;
	int key;
	int flag = 0;
	while (1)
	{

		if (_kbhit())
		{
			key = move();
			Common::gotoXY(64, line);
			switch (key)
			{
			case 3:
				LEFT--;
				if (LEFT < min)
					LEFT = max;
				break;
			case 4:
				LEFT++;
				if (LEFT > max)
					LEFT = min;
				break;
			case 1:
				flag = 1;
				break;
			case 2:
				flag = 1;
				break;
			}
			if (flag)
				break;
			Delete(54, line, 8);
			Common::gotoXY(54, line);
			cout << LEFT;
		}
	}
	return LEFT;
}

int Controller::setTop()
{
	int max = 100, min = 0;
	int line = 15;
	int key;
	int flag = 0;
	while (1)
	{

		if (_kbhit())
		{
			key = move();
			Common::gotoXY(64, line);
			switch (key)
			{
			case 3:
				TOP--;
				if (TOP < min)
					TOP = max;
				break;
			case 4:
				TOP++;
				if (TOP > max)
					TOP = min;
				break;
			case 1:
				flag = 1;
				break;
			case 2:
				flag = 1;
				break;
			}
			if (flag)
				break;
			Delete(54, line, 8);
			Common::gotoXY(54, line);
			cout << TOP;
		}
	}
	return TOP;
}