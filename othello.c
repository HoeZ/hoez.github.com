/* Othello Game : othello.c */
#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define IS_BLACK 1
#define IS_WHITE 2

int trueorfalse = 1;

// othello field : initial state(4 stones put on the center)
int field[8][8] = {
	{ 0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
	{ 0,0,0,2,1,0,0,0 },
	{ 0,0,0,1,2,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
};
int number = 0;
int giveup = 0;

void gotoXY(int x, int y);
int CheckStone(int ax, int ay);
int Game(int ax, int ay, int stoneColor);
void DrawArrayStone(int stoneColor);
int DrawStone(int ax, int ay, int x, int y);
void CheckStoneCount();
void InitialSetting();


int Game(int ax, int ay, int stoneColor)
{
	int endx, endy;
	endx = 0;
	endy = 0;
	int i, j;
	int stonetrue = 0;
	int tester[4] = { 0 };
	int tester2[4] = { 0 };
	int tester3[4] = { 0 };
	int tester4[4] = { 0 };
	int tester5[4] = { 0 };
	int PlusOneOrNot[4] = { 0 };
	int ArrayIndex = 0;
	int ere, dre;
	ere = 0;
	dre = 0;
	int g;
	if (field[ax + 1][ay] != stoneColor)
	{
		if (ax != 7)
		{
			if (field[ax + 1][ay] != 0)
			{
				for (j = ax + 1; j < 8; j++)
				{
					if (field[j][ay] == 0 || field[j][ay] > 2)
					{
						endx = ax;
						break;
					}
					if (field[j][ay] == stoneColor)
					{
						endx = j;
						break;
					}
				}
				for (i = ax + 1; i < endx + 1; i++)
				{
					if (field[i][ay] != stoneColor)
					{
						field[i][ay] = stoneColor;
						stonetrue = 1;
					}
				}
			}
		}
	}
	if (field[ax - 1][ay] != stoneColor)
	{
		if (ax != 0)
		{
			if (field[ax - 1][ay] != 0)
			{
				for (j = ax - 1; j >= 0; j--)
				{
					if (field[j][ay] == 0)
					{
						endx = ax;
						break;
					}
					if (field[j][ay] == stoneColor)
					{
						endx = j;
						break;
					}
				}
				for (i = ax - 1; i > endx - 1; i--)
				{
					if (field[j][ay] != stoneColor)
						break;
					if (field[i][ay] != stoneColor)
					{
						field[i][ay] = stoneColor;
						stonetrue = 1;
					}
				}
			}
		}
	}

	if (field[ax][ay - 1] != stoneColor)
	{
		if (ay != 0)
		{
			if (field[ax][ay - 1] != 0)
			{
				for (j = ay - 1; j >= 0; j--)
				{
					if (field[ax][j] == 0)
					{
						endy = ay;
						break;
					}
					if (field[ax][j] == stoneColor)
					{
						endy = j;
						break;
					}
				}
				for (i = ay - 1; i > endy - 1; i--)
				{
					if (field[ax][j] != stoneColor)
						break;
					if (field[ax][i] != stoneColor)
					{
						field[ax][i] = stoneColor;
						stonetrue = 1;
					}
				}
			}
		}
	}
	if (field[ax][ay + 1] != stoneColor)
	{
		if (ay != 7)
		{
			if (field[ax][ay + 1] != 0)
			{
				for (j = ay + 1; j < 8; j++)
				{
					if (field[ax][j] == 0 || field[ax][j] > 2)
					{
						endy = ay;
						break;
					}
					if (field[ax][j] == stoneColor)
					{
						endy = j;
						break;
					}
				}
				for (i = ay + 1; i < endy + 1; i++)
				{
					if (field[ax][i] != stoneColor)
					{
						field[ax][i] = stoneColor;
						stonetrue = 1;
					}
				}
			}
		}
	}
	if (field[ax - 1][ay - 1] != stoneColor)
	{
		if (ax != 0 && ay != 0)
		{
			if (field[ax - 1][ay - 1] != 0)
			{
				tester[0] = -1;
				tester2[0] = -1;
				tester3[0] = 0;
				tester4[0] = -2;
				tester5[0] = -1;
				PlusOneOrNot[0] = -1;
			}
		}
	} //test
	if (field[ax + 1][ay - 1] != stoneColor)
	{
		if (ax != 7 && ay != 0)
		{
			if (field[ax + 1][ay - 1] != 0)
			{
				if (tester[0] != 0)
					ArrayIndex++;
				tester[ArrayIndex] = 1;
				tester2[ArrayIndex] = -1;
				tester3[ArrayIndex] = 0;
				tester4[ArrayIndex] = 2;
				tester5[ArrayIndex] = -1;
				PlusOneOrNot[ArrayIndex] = -1;
			}
		}
	}
	if (field[ax - 1][ay + 1] != stoneColor)
	{
		if (ax != 0 && ay != 7)
		{
			if (field[ax - 1][ay + 1] != 0)
			{
				if (tester[0] != 0)
					ArrayIndex++;
				tester[ArrayIndex] = -1;
				tester2[ArrayIndex] = 1;
				tester3[ArrayIndex] = 7;
				tester4[ArrayIndex] = -2;
				tester5[ArrayIndex] = 1;
				PlusOneOrNot[ArrayIndex] = 1;
			}
		}
	}
	if (field[ax + 1][ay + 1] != stoneColor)
	{
		if (ax != 7 && ay != 7)
		{
			if (field[ax + 1][ay + 1] != 0)
			{
				if (tester[0] != 0)
					ArrayIndex++;
				tester[ArrayIndex] = 1;
				tester2[ArrayIndex] = 1;
				tester3[ArrayIndex] = 7;
				tester4[ArrayIndex] = 2;
				tester5[ArrayIndex] = 1;
				PlusOneOrNot[ArrayIndex] = 1;
			}
		}
	}
	if (tester[0] != 0)
	{
		for (g = 0; g <= ArrayIndex; g++)
		{
			if (field[ax + tester[g]][ay + tester2[g]] != stoneColor)
			{
				if (field[ax + tester[g]][ay + tester2[g]] != 0)
				{
					gotoXY(18, 18);
					ere = ax + tester[g];
					for (j = ay + tester2[g]; j != tester3[g]; j = j + PlusOneOrNot[g])
					{
						if (field[ere][j] == 0 || field[ere][j] > 2)
						{
							endy = ay;
							break;
						}
						if (field[ere][j] == stoneColor)
						{
							endx = ere;
							endy = j;
							break;
						}
						ere = ere + tester[g];
					}
					dre = ax + tester[g];
					for (i = ay + tester2[g]; i != j; i = i + PlusOneOrNot[g])
					{
						if (field[ere][j] != stoneColor)
							break;
						if (field[dre][i] != stoneColor)
						{
							field[dre][i] = stoneColor;
							stonetrue = 1;
						}
						dre = dre + tester[g];
					}
				}
			}
			gotoXY(15, 21);
		}
	}
	if (stonetrue == 0)
	{
		field[ax][ay] = 0;
	}
	else {
		if (trueorfalse == 0)
			trueorfalse = 1;
		else
			trueorfalse = 0;
		giveup = 0;
		gotoXY(10, 14);
		if (trueorfalse == 1)
			printf(">> Black stone turn");
		else
			printf(">> White stone turn");
		DrawArrayStone(stoneColor);
	}
}
void DrawArrayStone(int stoneColor)
{
	int i, j;	// index
	int x, y;
	x = 10;
	y = 3;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (field[j][i] == IS_BLACK)
			{
				gotoXY(x, y);
				printf("○");
			}
			else if (field[j][i] == IS_WHITE) {
				gotoXY(x, y);
				printf("●");
			}
			x += 2;
		}
		x = 10;
		y += 1;
	}
}
void gotoXY(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
int CheckStone(int ax, int ay)
{
	if (field[ax][ay] == 1 || field[ax][ay] == 2)
		return 1;
	else
		return 0;
}
int DrawStone(int ax, int ay, int x, int y)
{
	int stoneColor;
	if (trueorfalse == 1)
	{
		field[ax][ay] = 1;
		stoneColor = 1;
	}
	else if (trueorfalse == 0)
	{
		field[ax][ay] = 2;
		stoneColor = 2;
	}
	Game(ax, ay, stoneColor);
	return stoneColor;
}
void InitialSetting()
{
	printf("○");
	gotoXY(18, 7);
	printf("●");
	gotoXY(16, 6);
	printf("●");
	gotoXY(18, 6);
	printf("○");
	gotoXY(14, 7);
}
void CheckStoneCount()
{
	int i, j;
	int blackCount = 0, whiteCount = 0;
	gotoXY(10, 20);
	printf("\"Game over!\" \n");
	blackCount = 0;
	whiteCount = 0;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (field[i][j] == IS_BLACK)
				blackCount++;
			else if (field[i][j] == IS_WHITE)
				whiteCount++;
		}
	}
	gotoXY(10, 22);
	if (blackCount > whiteCount)
		printf("\"Black stone win!\" ");
	else if (blackCount < whiteCount)
		printf("\"White stone win!\" ");
	else if (blackCount == whiteCount)
		printf("\"Draw!\" ");
}

// 메인함수
int main() {
	int i, j, e, o;
	int x, y;
	int u, r;
	int ax, ay;
	int blackCount = 0, whiteCount = 0;
	char keycode;
	int stoneColor;

	gotoXY(10, 1);
	printf("* OTHELLO GAME *");
	gotoXY(10, 3);

	for (j = 3; j <= 10; j++)
	{
		for (i = 10; i <= 25; i++)
		{
			gotoXY(i, j);
			printf(".");
		}
	}
	gotoXY(16, 7);
	x = 16;
	y = 7;
	ax = 3;
	ay = 4;
	InitialSetting();
	gotoXY(10, 14);
	printf(">> Black stone turn");
	gotoXY(10, 16);
	printf("Put stone on : [direction key] + [Enter]");
	gotoXY(10, 18);
	printf("Pass turn : [z]");
	gotoXY(16, 7);
	while (1)
	{
		for (e = 0; e < 8; e++)
		{
			for (o = 0; o < 8; o++)
			{
				if (field[e][o] == 1 || field[e][o] == 2)
					number++;
			}
		}

		if (number == 64)
		{
			CheckStoneCount();
			system("pause>nul");
			return 0;
		}
		else
			number = 0;
		for (u = 0; u < 8; u++)
		{
			for (r = 0; r < 8; r++)
			{
				if (field[u][r] == 1)
					blackCount++;
				else if (field[u][r] == 2)
					whiteCount++;
			}
		}
		if (blackCount == 0 || whiteCount == 0)
		{
			gotoXY(10, 22);
			if (blackCount == 0)
				printf("\"White stone win!\" ");
			else if (whiteCount == 0)
				printf("\"Black stone win!\" ");
			system("pause>nul");
			return 0;
		}
		blackCount = 0;
		whiteCount = 0;
		if (_kbhit())	// keyboard hit
		{
			keycode = _getch();
			if (keycode == 75)
			{
				gotoXY(x - 2, y);
				x = x - 2;
				ax = ax - 1;
			}
			if (keycode == 77)
			{
				gotoXY(x + 2, y);
				x = x + 2;
				ax = ax + 1;
			}
			if (keycode == 72)
			{
				gotoXY(x, y - 1);
				y = y - 1;
				ay = ay - 1;
			}
			if (keycode == 80)
			{
				gotoXY(x, y + 1);
				y = y + 1;
				ay = ay + 1;
			}
			if (x >= 26)
			{
				gotoXY(24, y);
				x = 24;
				ax = 7;
			}
			if (x <= 8)
			{
				gotoXY(10, y);
				x = 10;
				ax = 0;
			}
			if (y <= 3)
			{
				gotoXY(x, 3);
				y = 3;
				ay = 0;
			}
			if (y >= 10)
			{
				gotoXY(x, 10);
				y = 10;
				ay = 7;
			}
			if (keycode == 'z')	// Pass turn
			{
				if (trueorfalse == 1)
				{
					trueorfalse = 0;
					gotoXY(10, 14);
					printf(">> White stone turn");
				}
				else if (trueorfalse == 0)
				{
					trueorfalse = 1;
					gotoXY(10, 14);
					printf(">> Black stone turn");
				}
				giveup++;
				if (giveup == 4)
				{
					CheckStoneCount();
					system("pause>nul"); // Game Over
					return 0;
				}
				gotoXY(x, y);
			}
			if (keycode == 13)
			{
				if (CheckStone(ax, ay) == 0)
					stoneColor = DrawStone(ax, ay, x, y);
				gotoXY(x, y);
			}
		}
	}
/* Othello Game */
#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define IS_BLACK 1
#define IS_WHITE 2

int trueorfalse = 1;

// othello field : initial state(4 stones put on the center)
int field[8][8] = {
	{ 0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
	{ 0,0,0,2,1,0,0,0 },
	{ 0,0,0,1,2,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
};
int number = 0;
int giveup = 0;

void gotoXY(int x, int y);
int CheckStone(int ax, int ay);
int Game(int ax, int ay, int stoneColor);
void DrawArrayStone(int stoneColor);
int DrawStone(int ax, int ay, int x, int y);
void CheckStoneCount();
void InitialSetting();


int Game(int ax, int ay, int stoneColor)
{
	int endx, endy;
	endx = 0;
	endy = 0;
	int i, j;
	int stonetrue = 0;
	int tester[4] = { 0 };
	int tester2[4] = { 0 };
	int tester3[4] = { 0 };
	int tester4[4] = { 0 };
	int tester5[4] = { 0 };
	int PlusOneOrNot[4] = { 0 };
	int ArrayIndex = 0;
	int ere, dre;
	ere = 0;
	dre = 0;
	int g;
	if (field[ax + 1][ay] != stoneColor)
	{
		if (ax != 7)
		{
			if (field[ax + 1][ay] != 0)
			{
				for (j = ax + 1; j < 8; j++)
				{
					if (field[j][ay] == 0 || field[j][ay] > 2)
					{
						endx = ax;
						break;
					}
					if (field[j][ay] == stoneColor)
					{
						endx = j;
						break;
					}
				}
				for (i = ax + 1; i < endx + 1; i++)
				{
					if (field[i][ay] != stoneColor)
					{
						field[i][ay] = stoneColor;
						stonetrue = 1;
					}
				}
			}
		}
	}
	if (field[ax - 1][ay] != stoneColor)
	{
		if (ax != 0)
		{
			if (field[ax - 1][ay] != 0)
			{
				for (j = ax - 1; j >= 0; j--)
				{
					if (field[j][ay] == 0)
					{
						endx = ax;
						break;
					}
					if (field[j][ay] == stoneColor)
					{
						endx = j;
						break;
					}
				}
				for (i = ax - 1; i > endx - 1; i--)
				{
					if (field[j][ay] != stoneColor)
						break;
					if (field[i][ay] != stoneColor)
					{
						field[i][ay] = stoneColor;
						stonetrue = 1;
					}
				}
			}
		}
	}

	if (field[ax][ay - 1] != stoneColor)
	{
		if (ay != 0)
		{
			if (field[ax][ay - 1] != 0)
			{
				for (j = ay - 1; j >= 0; j--)
				{
					if (field[ax][j] == 0)
					{
						endy = ay;
						break;
					}
					if (field[ax][j] == stoneColor)
					{
						endy = j;
						break;
					}
				}
				for (i = ay - 1; i > endy - 1; i--)
				{
					if (field[ax][j] != stoneColor)
						break;
					if (field[ax][i] != stoneColor)
					{
						field[ax][i] = stoneColor;
						stonetrue = 1;
					}
				}
			}
		}
	}
	if (field[ax][ay + 1] != stoneColor)
	{
		if (ay != 7)
		{
			if (field[ax][ay + 1] != 0)
			{
				for (j = ay + 1; j < 8; j++)
				{
					if (field[ax][j] == 0 || field[ax][j] > 2)
					{
						endy = ay;
						break;
					}
					if (field[ax][j] == stoneColor)
					{
						endy = j;
						break;
					}
				}
				for (i = ay + 1; i < endy + 1; i++)
				{
					if (field[ax][i] != stoneColor)
					{
						field[ax][i] = stoneColor;
						stonetrue = 1;
					}
				}
			}
		}
	}
	if (field[ax - 1][ay - 1] != stoneColor)
	{
		if (ax != 0 && ay != 0)
		{
			if (field[ax - 1][ay - 1] != 0)
			{
				tester[0] = -1;
				tester2[0] = -1;
				tester3[0] = 0;
				tester4[0] = -2;
				tester5[0] = -1;
				PlusOneOrNot[0] = -1;
			}
		}
	} //test
	if (field[ax + 1][ay - 1] != stoneColor)
	{
		if (ax != 7 && ay != 0)
		{
			if (field[ax + 1][ay - 1] != 0)
			{
				if (tester[0] != 0)
					ArrayIndex++;
				tester[ArrayIndex] = 1;
				tester2[ArrayIndex] = -1;
				tester3[ArrayIndex] = 0;
				tester4[ArrayIndex] = 2;
				tester5[ArrayIndex] = -1;
				PlusOneOrNot[ArrayIndex] = -1;
			}
		}
	}
	if (field[ax - 1][ay + 1] != stoneColor)
	{
		if (ax != 0 && ay != 7)
		{
			if (field[ax - 1][ay + 1] != 0)
			{
				if (tester[0] != 0)
					ArrayIndex++;
				tester[ArrayIndex] = -1;
				tester2[ArrayIndex] = 1;
				tester3[ArrayIndex] = 7;
				tester4[ArrayIndex] = -2;
				tester5[ArrayIndex] = 1;
				PlusOneOrNot[ArrayIndex] = 1;
			}
		}
	}
	if (field[ax + 1][ay + 1] != stoneColor)
	{
		if (ax != 7 && ay != 7)
		{
			if (field[ax + 1][ay + 1] != 0)
			{
				if (tester[0] != 0)
					ArrayIndex++;
				tester[ArrayIndex] = 1;
				tester2[ArrayIndex] = 1;
				tester3[ArrayIndex] = 7;
				tester4[ArrayIndex] = 2;
				tester5[ArrayIndex] = 1;
				PlusOneOrNot[ArrayIndex] = 1;
			}
		}
	}
	if (tester[0] != 0)
	{
		for (g = 0; g <= ArrayIndex; g++)
		{
			if (field[ax + tester[g]][ay + tester2[g]] != stoneColor)
			{
				if (field[ax + tester[g]][ay + tester2[g]] != 0)
				{
					gotoXY(18, 18);
					ere = ax + tester[g];
					for (j = ay + tester2[g]; j != tester3[g]; j = j + PlusOneOrNot[g])
					{
						if (field[ere][j] == 0 || field[ere][j] > 2)
						{
							endy = ay;
							break;
						}
						if (field[ere][j] == stoneColor)
						{
							endx = ere;
							endy = j;
							break;
						}
						ere = ere + tester[g];
					}
					dre = ax + tester[g];
					for (i = ay + tester2[g]; i != j; i = i + PlusOneOrNot[g])
					{
						if (field[ere][j] != stoneColor)
							break;
						if (field[dre][i] != stoneColor)
						{
							field[dre][i] = stoneColor;
							stonetrue = 1;
						}
						dre = dre + tester[g];
					}
				}
			}
			gotoXY(15, 21);
		}
	}
	if (stonetrue == 0)
	{
		field[ax][ay] = 0;
	}
	else {
		if (trueorfalse == 0)
			trueorfalse = 1;
		else
			trueorfalse = 0;
		giveup = 0;
		gotoXY(10, 14);
		if (trueorfalse == 1)
			printf(">> Black stone turn");
		else
			printf(">> White stone turn");
		DrawArrayStone(stoneColor);
	}
}
void DrawArrayStone(int stoneColor)
{
	int i, j;	// index
	int x, y;
	x = 10;
	y = 3;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (field[j][i] == IS_BLACK)
			{
				gotoXY(x, y);
				printf("○");
			}
			else if (field[j][i] == IS_WHITE) {
				gotoXY(x, y);
				printf("●");
			}
			x += 2;
		}
		x = 10;
		y += 1;
	}
}
void gotoXY(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
int CheckStone(int ax, int ay)
{
	if (field[ax][ay] == 1 || field[ax][ay] == 2)
		return 1;
	else
		return 0;
}
int DrawStone(int ax, int ay, int x, int y)
{
	int stoneColor;
	if (trueorfalse == 1)
	{
		field[ax][ay] = 1;
		stoneColor = 1;
	}
	else if (trueorfalse == 0)
	{
		field[ax][ay] = 2;
		stoneColor = 2;
	}
	Game(ax, ay, stoneColor);
	return stoneColor;
}
void InitialSetting()
{
	printf("○");
	gotoXY(18, 7);
	printf("●");
	gotoXY(16, 6);
	printf("●");
	gotoXY(18, 6);
	printf("○");
	gotoXY(14, 7);
}
void CheckStoneCount()
{
	int i, j;
	int blackCount = 0, whiteCount = 0;
	gotoXY(10, 20);
	printf("\"Game over!\" \n");
	blackCount = 0;
	whiteCount = 0;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (field[i][j] == IS_BLACK)
				blackCount++;
			else if (field[i][j] == IS_WHITE)
				whiteCount++;
		}
	}
	gotoXY(10, 22);
	if (blackCount > whiteCount)
		printf("\"Black stone win!\" ");
	else if (blackCount < whiteCount)
		printf("\"White stone win!\" ");
	else if (blackCount == whiteCount)
		printf("\"Draw!\" ");
}

// 메인함수
int main() {
	int i, j, e, o;
	int x, y;
	int u, r;
	int ax, ay;
	int blackCount = 0, whiteCount = 0;
	char keycode;
	int stoneColor;

	gotoXY(10, 1);
	printf("* OTHELLO GAME *");
	gotoXY(10, 3);

	for (j = 3; j <= 10; j++)
	{
		for (i = 10; i <= 25; i++)
		{
			gotoXY(i, j);
			printf(".");
		}
	}
	gotoXY(16, 7);
	x = 16;
	y = 7;
	ax = 3;
	ay = 4;
	InitialSetting();
	gotoXY(10, 14);
	printf(">> Black stone turn");
	gotoXY(10, 16);
	printf("Put stone on : [direction key] + [Enter]");
	gotoXY(10, 18);
	printf("Pass turn : [z]");
	gotoXY(16, 7);
	while (1)
	{
		for (e = 0; e < 8; e++)
		{
			for (o = 0; o < 8; o++)
			{
				if (field[e][o] == 1 || field[e][o] == 2)
					number++;
			}
		}

		if (number == 64)
		{
			CheckStoneCount();
			system("pause>nul");
			return 0;
		}
		else
			number = 0;
		for (u = 0; u < 8; u++)
		{
			for (r = 0; r < 8; r++)
			{
				if (field[u][r] == 1)
					blackCount++;
				else if (field[u][r] == 2)
					whiteCount++;
			}
		}
		if (blackCount == 0 || whiteCount == 0)
		{
			gotoXY(10, 22);
			if (blackCount == 0)
				printf("\"White stone win!\" ");
			else if (whiteCount == 0)
				printf("\"Black stone win!\" ");
			system("pause>nul");
			return 0;
		}
		blackCount = 0;
		whiteCount = 0;
		if (_kbhit())	// keyboard hit
		{
			keycode = _getch();
			if (keycode == 75)
			{
				gotoXY(x - 2, y);
				x = x - 2;
				ax = ax - 1;
			}
			if (keycode == 77)
			{
				gotoXY(x + 2, y);
				x = x + 2;
				ax = ax + 1;
			}
			if (keycode == 72)
			{
				gotoXY(x, y - 1);
				y = y - 1;
				ay = ay - 1;
			}
			if (keycode == 80)
			{
				gotoXY(x, y + 1);
				y = y + 1;
				ay = ay + 1;
			}
			if (x >= 26)
			{
				gotoXY(24, y);
				x = 24;
				ax = 7;
			}
			if (x <= 8)
			{
				gotoXY(10, y);
				x = 10;
				ax = 0;
			}
			if (y <= 3)
			{
				gotoXY(x, 3);
				y = 3;
				ay = 0;
			}
			if (y >= 10)
			{
				gotoXY(x, 10);
				y = 10;
				ay = 7;
			}
			if (keycode == 'z')	// Pass turn
			{
				if (trueorfalse == 1)
				{
					trueorfalse = 0;
					gotoXY(10, 14);
					printf(">> White stone turn");
				}
				else if (trueorfalse == 0)
				{
					trueorfalse = 1;
					gotoXY(10, 14);
					printf(">> Black stone turn");
				}
				giveup++;
				if (giveup == 4)
				{
					CheckStoneCount();
					system("pause>nul"); // Game Over
					return 0;
				}
				gotoXY(x, y);
			}
			if (keycode == 13)
			{
				if (CheckStone(ax, ay) == 0)
					stoneColor = DrawStone(ax, ay, x, y);
				gotoXY(x, y);
			}
		}
	}
}