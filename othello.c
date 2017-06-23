/* Othello Game : othello.c */
#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define IS_BLACK 1
#define IS_WHITE 2

// othello field (8X8)
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

// global values
int isValid = 1;
int count = 0;
int passTurn = 0;

// functions
void InitialSetting();
void seekXY(int x, int y);
int CheckStone(int ax, int ay);
int OthelloGame(int ax, int ay, int stoneColor);
void DrawArrayStone(int stoneColor);
int DrawStone(int ax, int ay, int x, int y);
void CheckStoneCount();

// initial setting : initial state(4 stones put on the center)
void InitialSetting()
{
	printf("○");	// ○ : Black stone
	seekXY(18, 7);	// ● : White stone
	printf("●");
	seekXY(16, 6);
	printf("●");
	seekXY(18, 6);
	printf("○");
	seekXY(14, 7);
}

// seek (x, y) point of console window
void seekXY(int x, int y)
{
	COORD Pos;	// struct COORD
	Pos.X = x; // x coordinate
	Pos.Y = y; // y coordinate
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

// game code
int OthelloGame(int ax, int ay, int stoneColor)
{
	int endx, endy;
	endx = 0;
	endy = 0;
	int i, j;
	int stoneTrue = 0;
	// checker : check whether the stone can be put or not
	int checker1[4] = { 0 };
	int checker2[4] = { 0 };
	int checker3[4] = { 0 };
	int checker4[4] = { 0 };
	int checker5[4] = { 0 };
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
						stoneTrue = 1;
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
						stoneTrue = 1;
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
						stoneTrue = 1;
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
						stoneTrue = 1;
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
				checker1[0] = -1;
				checker2[0] = -1;
				checker3[0] = 0;
				checker4[0] = -2;
				checker5[0] = -1;
				PlusOneOrNot[0] = -1;
			}
		}
	} // check
	// check whether the stone can be put or not
	if (field[ax + 1][ay - 1] != stoneColor)
	{
		if (ax != 7 && ay != 0)
		{
			if (field[ax + 1][ay - 1] != 0)
			{
				if (checker1[0] != 0)
					ArrayIndex++;
				checker1[ArrayIndex] = 1;
				checker2[ArrayIndex] = -1;
				checker3[ArrayIndex] = 0;
				checker4[ArrayIndex] = 2;
				checker5[ArrayIndex] = -1;
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
				if (checker1[0] != 0)
					ArrayIndex++;
				checker1[ArrayIndex] = -1;
				checker2[ArrayIndex] = 1;
				checker3[ArrayIndex] = 7;
				checker4[ArrayIndex] = -2;
				checker5[ArrayIndex] = 1;
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
				if (checker1[0] != 0)
					ArrayIndex++;
				checker1[ArrayIndex] = 1;
				checker2[ArrayIndex] = 1;
				checker3[ArrayIndex] = 7;
				checker4[ArrayIndex] = 2;
				checker5[ArrayIndex] = 1;
				PlusOneOrNot[ArrayIndex] = 1;
			}
		}
	}
	if (checker1[0] != 0)
	{
		for (g = 0; g <= ArrayIndex; g++)
		{
			if (field[ax + checker1[g]][ay + checker2[g]] != stoneColor)
			{
				if (field[ax + checker1[g]][ay + checker2[g]] != 0)
				{
					seekXY(18, 18);
					ere = ax + checker1[g];
					for (j = ay + checker2[g]; j != checker3[g]; j = j + PlusOneOrNot[g])
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
						ere = ere + checker1[g];
					}
					dre = ax + checker1[g];
					for (i = ay + checker2[g]; i != j; i = i + PlusOneOrNot[g])
					{
						if (field[ere][j] != stoneColor)
							break;
						if (field[dre][i] != stoneColor)
						{
							field[dre][i] = stoneColor;
							stoneTrue = 1;
						}
						dre = dre + checker1[g];
					}
				}
			}
			seekXY(15, 21);
		}
	}
	if (stoneTrue == 0)
	{
		field[ax][ay] = 0;
	}
	else {
		if (isValid == 0)
			isValid = 1;
		else
			isValid = 0;
		passTurn = 0;
		seekXY(10, 14);
		if (isValid == 1)
			printf(">> Black stone turn");
		else
			printf(">> White stone turn");
		DrawArrayStone(stoneColor);
	}
}

// draw stones on the filed array
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
				seekXY(x, y);
				printf("○");
			}
			else if (field[j][i] == IS_WHITE) {
				seekXY(x, y);
				printf("●");
			}
			x += 2;
		}
		x = 10;
		y += 1;
	}
}

// check stone (black/white)
int CheckStone(int ax, int ay)
{
	if (field[ax][ay] == IS_BLACK || field[ax][ay] == IS_WHITE)
		return 1;
	else
		return 0;
}

// draw stone
int DrawStone(int ax, int ay, int x, int y)
{
	int stoneColor;
	if (isValid == 1)
	{
		field[ax][ay] = IS_BLACK;	// black : 1
		stoneColor = 1;
	}
	else if (isValid == 0)
	{
		field[ax][ay] = IS_WHITE; // white : 2
		stoneColor = 2;
	}
	OthelloGame(ax, ay, stoneColor);
	return stoneColor;
}

// check the number(count) of stones
void CheckStoneCount()
{
	int i, j;
	int blackCount, whiteCount;
	seekXY(10, 20);
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
	seekXY(10, 22);
	// match result
	if (blackCount > whiteCount)
		printf("\"Black stone win!\" ");
	else if (blackCount < whiteCount)
		printf("\"White stone win!\" ");
	else if (blackCount == whiteCount)
		printf("\"Draw!\" ");
}

// main function
int main() {
	int i, j, e, o;
	int x, y;
	int u, r;
	int ax, ay;
	int blackCount = 0, whiteCount = 0;
	char keycode;
	int stoneColor;

	seekXY(10, 1);
	printf("* OTHELLO GAME *");
	seekXY(10, 3);

	for (j = 3; j <= 10; j++)
	{
		for (i = 10; i <= 25; i++)
		{
			seekXY(i, j);
			printf(".");
		}
	}
	seekXY(16, 7);
	x = 16;
	y = 7;
	ax = 3;
	ay = 4;
	InitialSetting();
	seekXY(10, 14);
	printf(">> Black stone turn");
	seekXY(10, 16);
	printf("Put stone on : [direction key] + [Enter]");
	seekXY(10, 18);
	printf("Pass turn : [z]");
	seekXY(16, 7);
	while (1)
	{
		for (e = 0; e < 8; e++)
		{
			for (o = 0; o < 8; o++)
			{
				if (field[e][o] == IS_BLACK || field[e][o] == IS_WHITE)
					count++;
			}
		}

		if (count == 64)	// if the field is full filled
		{
			CheckStoneCount();
			system("pause>nul");	// Game Over
			return 0;
		}
		else
			count = 0;
		for (u = 0; u < 8; u++)
		{
			for (r = 0; r < 8; r++)
			{
				if (field[u][r] == IS_BLACK)
					blackCount++;
				else if (field[u][r] == IS_WHITE)
					whiteCount++;
			}
		}
		if (blackCount == 0 || whiteCount == 0)
		{
			seekXY(10, 22);
			if (blackCount == 0)
				printf("\"White stone win!\" ");
			else if (whiteCount == 0)
				printf("\"Black stone win!\" ");
			system("pause>nul");	// Game Over
			return 0;
		}
		blackCount = 0;
		whiteCount = 0;
		if (_kbhit())	// keyboard hit
		{
			keycode = _getch();
			if (keycode == 75)
			{
				seekXY(x - 2, y);
				x = x - 2;
				ax = ax - 1;
			}
			if (keycode == 77)
			{
				seekXY(x + 2, y);
				x = x + 2;
				ax = ax + 1;
			}
			if (keycode == 72)
			{
				seekXY(x, y - 1);
				y = y - 1;
				ay = ay - 1;
			}
			if (keycode == 80)
			{
				seekXY(x, y + 1);
				y = y + 1;
				ay = ay + 1;
			}
			if (x >= 26)
			{
				seekXY(24, y);
				x = 24;
				ax = 7;
			}
			if (x <= 8)
			{
				seekXY(10, y);
				x = 10;
				ax = 0;
			}
			if (y <= 3)
			{
				seekXY(x, 3);
				y = 3;
				ay = 0;
			}
			if (y >= 10)
			{
				seekXY(x, 10);
				y = 10;
				ay = 7;
			}
			if (keycode == 'z')	// Pass turn
			{
				if (isValid == 1)
				{
					isValid = 0;
					seekXY(10, 14);
					printf(">> White stone turn");
				}
				else if (isValid == 0)
				{
					isValid = 1;
					seekXY(10, 14);
					printf(">> Black stone turn");
				}
				passTurn++;
				// 4 times pass turn : assume that anyone can not put a stone anymore
				if (passTurn == 4)
				{
					CheckStoneCount();
					system("pause>nul"); // Game Over
					return 0;
				}
				seekXY(x, y);
			}
			if (keycode == 13)
			{
				if (CheckStone(ax, ay) == 0)
					stoneColor = DrawStone(ax, ay, x, y);
				seekXY(x, y);
			}
		}
	}
}
