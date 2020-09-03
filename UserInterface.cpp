#include "UserInterface.h"

int UserInterface::gameMenu()
{
	system("cls");
	Common::hideCursor(FALSE);
	int key, X = 65, Y = 21;
	int line = 22, prevline = 22;
	int choose = 1; // return 1,2 3
	string s[4] = { "      1. New Game      " ,"      2. Load Game     ", "      3. Setting       ",
	"      4. Exit          " };
	Common::gotoXY(X, Y);
	UserInterface::gameName(243);
	Common::gotoXY(X, Y + 1);
	Controller::setTextColor(27);
	cout << s[0];
	Common::gotoXY(X, Y+2);
	Controller::setTextColor(240);
	cout << s[1];
	Common::gotoXY(X, Y+3);
	cout << s[2];
	Common::gotoXY(X, Y + 4);
	cout << s[3];
	while (1) 
	{
		if (_kbhit())
		{
			key = Controller::move();
			Common::gotoXY(X, line);
			switch (key)
			{
			case 1:
				line--;
				if (line < 22)
					line = 25;
				break;
			case 2:
				line++;
				if (line > 25)
					line = 22;
				break;	
			case 13:
				choose = line - 21;
				return choose;
			}
			Common::gotoXY(X, line);
			Controller::setTextColor(27);
			cout << s[line - 22];
			Common::gotoXY(X, prevline);
			Controller::setTextColor(240);
			cout << s[prevline - 22];
			prevline = line;
		}
	}
}

void UserInterface::settingMenu(string& music, int& volume)
{
	system("cls");
	Common::hideCursor(FALSE);
	music = "ChocoboRacingCidsTestCourse";
	volume = 100;
	Common::gotoXY(40, 10);
	string m[3] = { "  Music:<[                                      ]>" ,"  Volume:<[            ]>                          " ,"                      SAVE                       " };

	cout << "                    SETTINGS             " << endl;
	Common::gotoXY(40, 11);
	Controller::setTextColor(27);
	cout << m[0];
	Controller::setTextColor(240);
	Common::gotoXY(40, 12);
	cout << m[1];
	Common::gotoXY(40, 13);
	cout << m[2];
	int key;
	int line = 11, prevline = 11;
	while (1)
	{
		key = Controller::move();
		Common::gotoXY(40, line);
		Controller::setTextColor(27);
		cout << m[line - 11];
		switch (key)
		{
		case 1:
			line--;
			if (line < 11)
				line = 13;
			break;
		case 2:
			line++;
			if (line > 13)
				line = 11;
			break;
		case 3:
		case 4:
			Common::gotoXY(54, line);
			if (line == 11)
			{
				music = Controller::setMusic();
			}
			else if (line == 12)
			{
				volume = Controller::setVolume();
			}
			else
				continue;
			break;
		case 13:
			if (line == 13)
			{
				return;
			}
		}
		Common::gotoXY(40, line);
		Controller::setTextColor(27);
		cout << m[line - 11];
		Common::gotoXY(54, line);
		if (line == 11) cout << music;
		else if(line == 12) cout << volume;
		Common::gotoXY(40, prevline);
		Controller::setTextColor(240);
		cout << m[prevline - 11];
		Common::gotoXY(54, prevline);
		if (prevline == 11) cout << music;
		else if (prevline == 12) cout << volume;
		prevline = line;
	}
}

int UserInterface::playGameMenu()
{
	system("cls");
	Common::hideCursor(FALSE);
	int key, X = 50, Y = 10;
	int line = 11, prevline = 11;
	int choose = 1; // return 1,2 3
	string s[2] = { "      1. Player vs Player      " ,"      2. Player vs Computer     "};
	Common::gotoXY(X, Y + 1);
	Controller::setTextColor(27);
	cout << s[0];
	Common::gotoXY(X, Y + 2);
	Controller::setTextColor(240);
	cout << s[1];
	Common::gotoXY(X - 2, Y + 1);
	while (1)
	{
		if (_kbhit())
		{
			key = Controller::move();
			Common::gotoXY(X, line);
			switch (key)
			{
			case 1:
				line--;
				if (line < 11)
					line = 12;
				break;
			case 2:
				line++;
				if (line > 12)
					line = 11;
				break;
			case 13:
				choose = line - 10;
				return choose;
			}
			Common::gotoXY(X, line);
			Controller::setTextColor(27);
			cout << s[line - 11];

			Common::gotoXY(X, prevline);
			Controller::setTextColor(240);
			cout << s[prevline - 11];
			prevline = line;
		}
	}
}

void UserInterface::Result(string filename)
{
	system("cls");
	fstream f;
	string s;
	f.open(filename, ios::in);
	Controller::setTextColor(243);
	int i = 10;
	while (!f.eof())
	{
		getline(f, s);
		Common::gotoXY(40, i++);
		cout << s << endl;
	}
}

int UserInterface::difficulty()
{
	system("cls");
	Common::hideCursor(FALSE);
	int key, X = 50, Y = 10;
	int line = 11, prevline = 11;
	int choose = 1; // return 1,2 3
	string s[2] = { "      1. Easy        " ,"      2. Difficult     " };
	Common::gotoXY(X, Y + 1);
	Controller::setTextColor(27);
	cout << s[0];
	Common::gotoXY(X, Y + 2);
	Controller::setTextColor(240);
	cout << s[1];
	Common::gotoXY(X - 2, Y + 1);
	while (1)
	{
		if (_kbhit())
		{
			key = Controller::move();
			Common::gotoXY(X, line);
			switch (key)
			{
			case 1:
				line--;
				if (line < 11)
					line = 12;
				break;
			case 2:
				line++;
				if (line > 12)
					line = 11;
				break;
			case 13:
				choose = line - 10;
				return choose;
			}
			Common::gotoXY(X, line);
			Controller::setTextColor(27);
			cout << s[line - 11];

			Common::gotoXY(X, prevline);
			Controller::setTextColor(240);
			cout << s[prevline - 11];
			prevline = line;
		}
	}
}

void UserInterface::gameName(int color)
{
	string s;
	fstream f;
	f.open("CARO1.txt", ios::in);
	int i = 0;
	Controller::setTextColor(color);
	while (!f.eof())
	{
		getline(f, s);
		Common::gotoXY(25, i++);
		cout << s << endl;
	}
}
void UserInterface::Load()
{
	system("cls");
	Common::hideCursor(FALSE);
	gameName(250);
	Common::gotoXY(50,25);
	cout << "___________________________________________________" << endl;
	Common::gotoXY(50, 26);
	cout << "___________________________________________________";
	for (int i = 0; i <= 100; i++)
	{
		Common::gotoXY(50+(i/2), 26);
		if(i%2 == 0)
			cout << char(219);
		Common::gotoXY(67, 28);
		cout << "Loading... " << i << " %";
		if (i <= 85)
			Sleep(int(3000 / (i + 1)));
		else
			Sleep(int(18000 / i));
		if (i == 0)
		{
			Common::gotoXY(50, 35);
			cout << "Tip: You can back to main menu by press B when playing";
		}
		else if (i == 80)
		{
			Common::gotoXY(50, 35);
			cout << "Tip: Press L to save your game";
		}
	}
	Common::gotoXY(67, 28);
	cout << "Starting game...";
	Sleep(3000);
}