#include"Player.h"

void Player::drawInfo(string name, int left, int top)
{
	Common::gotoXY(left, top + 2 * (-1));
	cout << "_________________";
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			Common::gotoXY(left + 4 * i, top + 2 * j);
			if (i == 0 || i == 4) cout << "|";
		}
	}
	Common::gotoXY(left, top + 2 * 4.5);
	cout << "_________________";
	Common::gotoXY(left + 1, top - 1);
	cout << "   " << name << "    ";
	Common::gotoXY(left + 1, top + 3.5);
	cout << " Move:  " << getMove();
	Common::gotoXY(left + 1, top + 4.5);
	cout << " Score:  " << getnumWin();
}

Player::Player()
{
	move = 0;
	numWin = 0;
}

int Player::getMove()
{
	return move;
}

void Player::IncreaseMove()
{
	move++;
}

int Player::getnumWin()
{
	return numWin;
}

void Player::IncreaseWin()
{
	numWin++;
}

void Player::SetMove(const int m)
{
	move = m;
}

Player::Player(const Player& p)
{
	move = p.move;
	numWin = p.numWin;
}