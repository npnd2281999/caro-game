#include "PlayGame.h"


void PlayGame::PvP(Game g1)
{

		Common::hideCursor(TRUE);
		Game g(g1);
		g.startGame();
		while (g.isContinue()) {
			g.waitKeyBoard();
			if (g.getCommand() == 27) g.exitGame();
			else {
				switch (g.getCommand()) {
				case 'A':case 75:
					g.moveLeft();
					break;
				case 'W':case 72:
					g.moveUp();
					break;
				case 'S':case 80:
				g.moveDown();
				break;
			case 'D':case 77:
				g.moveRight();
				break;
			case 'B':
				g.exitGame();
				break;
			case 'L':
				g.SaveGame();
				g.exitGame();
				break;
			case 13:
				//Đánh dấu bàn cờ, sau đó kiểm tra và xử lý thắng/thua/hòa/tiếp tục
				if (g.processCheckBoard()) {
					switch (g.processFinish()) {
					case -1:
					case 1:
					case 0:
						if (g.askContinue() != 'Y') g.exitGame();
						else
						{
							g.startGame();
						}
						break;
					}
				}
			}
		}
	}
}

void PlayGame::PvCRandom(Game g1)
{
	int dx[24] = { -2,-2,-2,-2,-2,-1,-1,-1,-1,-1,0,0,0,0,1,1,1,1,1, 2,2,2,2,2 };
	int dy[24] = { -2,-1,0,1,2,-2,-1,0,1,2,-2,-1,1,2,-2,-1,0,1,0,-2,-1,0,1,2 };
	srand((unsigned int)time(NULL));
	Common::hideCursor(TRUE);
	Game g(g1);
	g.startGame();
	int t;
	while (g.isContinue()) {
		g.waitKeyBoard();
		if (g.getCommand() == 27) g.exitGame();
		else {
			switch (g.getCommand()) {
			case 'A': case 75:
				g.moveLeft();
				break;
			case 'W': case 72:
				g.moveUp();
				break;
			case 'S':case 80:
				g.moveDown();
				break;
			case 'D': case 77:
				g.moveRight();
				break;
			case 'B':
				g.exitGame();
				break;
			case 'L':
				g.SaveGame();
				g.exitGame();
				break;
			case 13:
				//Đánh dấu bàn cờ, sau đó kiểm tra và xử lý thắng/thua/hòa/tiếp tục
				if (g.processCheckBoard()) {
					switch (g.processFinish()) {
					case -1: case 1: case 0:
						if (g.askContinue() != 'Y') g.exitGame();
						else g.startGame();
					}
					int i = 1;
					while (!g.processCheckBoard())
					{
						t = rand() % 23 + 0;
						switch (dy[t])
						{
						case 0:
							break;
						case 1:
							g.moveRight();
							break;
						case 2:
							g.moveRight();
							g.moveRight();
							break;
						case -1:
							g.moveLeft();
							break;
						case -2:
							g.moveLeft();
							g.moveLeft();
							break;
						}
						switch (dx[t])
						{
						case 0:
							break;
						case 1:
							g.moveDown();
							break;
						case 2:
							g.moveDown();
							g.moveDown();
							break;
						case -1:
							g.moveUp();
							break;
						case -2:
							g.moveUp();
							g.moveUp();
							break;
						}
						i++;
						if (i > 25)
						{
							while (!g.processCheckBoard())
							{
								int k= rand() % 4 + 1;
								switch (k)
								{
								case 1:
									g.moveDown();
									break;
								case 2:
									g.moveLeft();
									break;
								case 3:
									g.moveRight();
									break;
								case 4:
									g.moveUp();
									break;
								}
							}
						}
					}
					switch (g.processFinish()) {
					case -1: case 1: case 0:
						if (g.askContinue() != 'Y') g.exitGame();
						else g.startGame();
					}
				}
			}
		}
	}
}

void PlayGame::PvAI(Game g1)
{
	COORD bestMove;
	Common::hideCursor(TRUE);
	Game g(g1);
	g.startGame();
	while (g.isContinue()) {
		g.waitKeyBoard();
		if (g.getCommand() == 27) g.exitGame();
		else {
			switch (g.getCommand()) {
			case 'A':case 75:
				g.moveLeft();
				break;
			case 'W':case 72:
				g.moveUp();
				break;
			case 'S':case 80:
				g.moveDown();
				break;
			case 'D':case 77:
				g.moveRight();
				break;
			case 'B':
				g.exitGame();
				break;
			case 'L':
				g.SaveGame();
				g.exitGame();
				break;
			case 13:
				//Đánh dấu bàn cờ, sau đó kiểm tra và xử lý thắng/thua/hòa/tiếp tục
				if (g.processCheckBoard()) {
					switch (g.processFinish()) {
					case -1:
					case 1:
					case 0:
						if (g.askContinue() != 'Y') g.exitGame();
						else
						{
							g.startGame();
						}
						break;
					}
					g.move(bestMove);
					switch (g.processFinish()) {
					case -1: case 1: case 0:
						if (g.askContinue() != 'Y') g.exitGame();
						else g.startGame();
					}
				}

			}
		}
	}
}