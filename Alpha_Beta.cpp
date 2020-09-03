#include "Alpha_Beta.h"

COORD AlphaBeta::minimax(int n, int m,bool turn)
{
	int CS;
	int best = BestScoreState(n, m); int s = turn ? -1 : 1;
	if (best >= 900)
	{
		COORD C = { -1,-1 };
	} // sẽ thua
	for (int i = 0; i < b->getSize(); i++)
	{
		for (int j = 0; j < b->getSize(); j++)
		{
			if (b->getCheck(i, j) == 0)
			{
				b->setCheckAt(i, j, s);
				CS = BestScoreState(i, j);
				if (CS > BestScoreState(n, m))
				{
					COORD C = { i,j };
					return C;
				}
				else
				{
					b->setCheckAt(i, j, 0);
					continue;
				}
			}
		}
	}

}


int AlphaBeta::ScoreState(int i, int j)
{
	int check = b->getCheck(i, j);
	string State[4] = { "####O####","####O####","####O####","####O####" };
	for (int k = 1; k <= 4; k++)
	{
		if (j - k >= 0)
		{
			if (b->getCheck(i, j - k) == check)
				State[1][4 - k] = 'O';
			else if (b->getCheck(i, j - k) == 0)
				State[1][4 - k] = '*';
		}
		if (j + k < b->getSize())
		{
			if (b->getCheck(i, j + k) == check)
				State[1][4 + k] = 'O';
			else if (b->getCheck(i, j + k) == 0)
				State[1][4 + k] = '*';
		}
		if (i - k >= 0)
		{
			if (b->getCheck(i - k, j) == check)
				State[2][4 - k] = 'O';
			else if (b->getCheck(i - k, j) == 0)
				State[2][4 - k] = '*';
		}
		if (i + k < b->getSize())
		{
			if (b->getCheck(i + k, j) == check)
				State[2][4 + k] = 'O';
			else if (b->getCheck(i - k, j) == 0)
				State[2][4 + k] = '*';
		}
		if (i - k >= 0 && j - k >= 0)
		{
			if (b->getCheck(i - k, j - k) == check)
				State[3][4 - k] = 'O';
			else if (b->getCheck(i - k, j - k) == 0)
				State[3][4 - k] = '*';
		}
		if (i + k < b->getSize() && j + k < b->getSize())
		{
			if (b->getCheck(i + k, j + k) == check)
				State[3][4 + k] = 'O';
			else if (b->getCheck(i + k, j + k) == 0)
				State[3][4 + k] = '*';
		}
		if (i - k >= 0 && j + k < b->getSize())
		{
			if (b->getCheck(i - k, j + k) == check)
				State[3][4 - k] = 'O';
			else if (b->getCheck(i - k, j + k) == 0)
				State[3][4 - k] = '*';
		}
		if (i + k < b->getSize() && j - k >= 0)
		{
			if (b->getCheck(i + k, j - k) == check)
				State[3][4 + k] = 'O';
			else if (b->getCheck(i + k, j - k) == 0)
				State[3][4 + k] = '*';
		}
	}
	string cmp[961]; int score[961];
	getCmpState(cmp, score);
	int S[4] = { 0 };
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 961; j++)
		{
			if (strcmp(State[i].c_str(), cmp[j].c_str()) == 0)
			{
				S[i] = score[j];
				break;
			}
		}
	}
	return Max(S, 4);
}

int AlphaBeta::Min(int a[], int n)
{
	int min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
	}
	return min;
}

int AlphaBeta::Max(int a[], int n)
{
	int max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	return max;
}

void AlphaBeta::getCmpState(string cmp[], int Score[])
{
	ifstream f; f.open("Data.txt");
	int i = 0;
	while (!f.eof())
	{
		f >> Score[i] >> cmp[i];
		i++;
	}
}

int AlphaBeta::BestScoreState(int n, int m)
{
	int pCheck = b->getCheck(n, m);
	int a[100] = { 0 };
	int k = 0;
	for (int i = 0; i < b->getSize(); i++)
	{
		for (int j = 0; j < b->getSize(); j++)
		{
			if (b->getCheck(i, j) == pCheck)
			{
				a[k++] = ScoreState(i, j);
			}
		}
	}
	return Max(a, 100);
}