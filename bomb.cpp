#include <iostream>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;

int space[25][51];
bool f_player = true;
int x_player, y_player, x_bomb, y_bomb;
int x_computer[10], y_computer[10], d_computer[10];
bool f_computer[10];

void boom_player()
{
	bool f_1 = true, f_2 = true, f_3 = true, f_4 = true;
	if (space[x_bomb][y_bomb] == 6)
		space[x_bomb][y_bomb] = 0;
	else
		f_player = 0;
	space[x_bomb][y_bomb] = 9;
	if (space[x_bomb + 1][y_bomb] != 3 && space[x_bomb + 1][y_bomb] != 1 && space[x_bomb + 1][y_bomb] != 2)
		if (space[x_bomb + 1][y_bomb] != 4)
		{
			if (space[x_bomb + 1][y_bomb] != 5)
				if (space[x_bomb + 1][y_bomb] != 7)
					space[x_bomb + 1][y_bomb] = 9;
				else
				{
					f_1 = false;
					space[x_bomb + 1][y_bomb] = 9;
				}
			else
				for (int i = 0; i <= 9; i++)
					if (x_bomb + 1 == x_computer[i] && y_bomb == y_computer[i])
						f_computer[i] = false;
		}
		else
			f_player = 0;
	if (f_1 && space[x_bomb + 2][y_bomb] != 3 && space[x_bomb + 2][y_bomb] != 1 && space[x_bomb + 2][y_bomb] != 2)
		if (space[x_bomb+2][y_bomb] != 4)
		{
			if (space[x_bomb+2][y_bomb] != 5)
				space[x_bomb+2][y_bomb] = 9;
			else
				for (int i = 0; i <= 9; i++)
					if (x_bomb + 2 == x_computer[i] && y_bomb == y_computer[i])
						f_computer[i] = false;
		}
		else
			f_player = 0;
	if (space[x_bomb - 1][y_bomb] != 3 && space[x_bomb - 1][y_bomb] != 1 && space[x_bomb - 1][y_bomb] != 2)
		if (space[x_bomb - 1][y_bomb] != 4)
		{
			if (space[x_bomb - 1][y_bomb] != 5)
				if (space[x_bomb - 1][y_bomb] != 7)
					space[x_bomb - 1][y_bomb] = 9;
				else
				{
					f_2 = false;
					space[x_bomb - 1][y_bomb] = 9;
				}
			else
				for (int i = 0; i <= 9; i++)
					if (x_bomb - 1 == x_computer[i] && y_bomb == y_computer[i])
						f_computer[i] = false;
		}
		else
			f_player = 0;
	if (f_2 && space[x_bomb - 2][y_bomb] != 3 && space[x_bomb - 2][y_bomb] != 1 && space[x_bomb - 2][y_bomb] != 2)
		if (space[x_bomb - 2][y_bomb] != 4)
		{
			if (space[x_bomb - 2][y_bomb] != 5)
				space[x_bomb - 2][y_bomb] = 9;
			else
				for (int i = 0; i <= 9; i++)
					if (x_bomb - 2 == x_computer[i] && y_bomb == y_computer[i])
						f_computer[i] = false;
		}
		else
			f_player = 0;
	if (space[x_bomb][y_bomb - 1] != 3 && space[x_bomb][y_bomb - 1] != 1 && space[x_bomb][y_bomb - 1] != 2)
		if (space[x_bomb][y_bomb - 1] != 4)
		{
			if (space[x_bomb][y_bomb - 1] != 5)
				if (space[x_bomb][y_bomb - 1] != 7)
					space[x_bomb][y_bomb - 1] = 9;
				else
				{
					f_3 = false;
					space[x_bomb][y_bomb - 1] = 9;
				}
			else
				for (int i = 0; i <= 9; i++)
					if (x_bomb == x_computer[i] && y_bomb - 1 == y_computer[i])
						f_computer[i] = false;
		}
		else
			f_player = 0;
	if (f_3 && space[x_bomb][y_bomb - 1] != 3 && space[x_bomb][y_bomb - 1] != 1 && space[x_bomb][y_bomb - 1] != 2)
		if (space[x_bomb][y_bomb - 2] != 4)
		{
			if (space[x_bomb][y_bomb - 2] != 5)
				space[x_bomb][y_bomb - 2] = 9;
			else
				for (int i = 0; i <= 9; i++)
					if (x_bomb == x_computer[i] && y_bomb - 2 == y_computer[i])
						f_computer[i] = false;
		}
		else
			f_player = 0;
	if (space[x_bomb][y_bomb + 1] != 3 && space[x_bomb][y_bomb + 1] != 1 && space[x_bomb][y_bomb + 1] != 2)
		if (space[x_bomb][y_bomb + 1] != 4)
		{
			if (space[x_bomb][y_bomb + 1] != 5)
				if (space[x_bomb][y_bomb + 1] != 7)
					space[x_bomb][y_bomb + 1] = 9;
				else
				{
					f_4=false;
					space[x_bomb][y_bomb + 1] = 9;
				}
			else
				for (int i = 0; i <= 9; i++)
					if (x_bomb == x_computer[i] && y_bomb + 1 == y_computer[i])
						f_computer[i] = false;
		}
		else
			f_player = 0;
	if (f_4 && space[x_bomb][y_bomb + 1] != 3 && space[x_bomb][y_bomb + 1] != 1 && space[x_bomb][y_bomb + 1] != 2)
		if (space[x_bomb][y_bomb+2] != 4)
		{
			if (space[x_bomb][y_bomb+2] != 5)
				space[x_bomb][y_bomb+2] = 9;
			else
				for (int i = 0; i <= 9; i++)
					if (x_bomb == x_computer[i] && y_bomb + 2 == y_computer[i])
						f_computer[i] = false;
		}
		else
			f_player = 0;
	return;
}

void init()
{
	srand(time(0));
	for (int i = 0; i <= 24; i++)
		for (int j = 0; j <= 50; j++)
		{
			space[i][j] = 0;
			if (i % 2 == 0 && j % 2 == 0)
				space[i][j] = 3;
			if (i == 0 || i == 24)
				space[i][j] = 1;
			if (j == 0 || j == 50)
				space[i][j] = 2;
		}
	space[0][0] = 1;
	space[0][50] = 1;
	space[1][1] = 4;
	x_player = 1;
	y_player = 1;
	int i, j;
	for (int p = 1; p <= rand() % 40 + 81; p++)
	{
		do
		{
			i = rand() % 24 + 1;
			j = rand() % 50 + 1;
		}while (space[i][j] != 0);
		space[i][j] = 7;
	}
	space[1][2] = 0;
	space[2][1] = 0;
	for (int p = 0; p <= 9; p++)
	{
		bool flag = true;
		do
		{
			i = rand() % 24 + 1;
			j = rand() % 50 + 1;
			if (space[i][j] == 0)
				flag = false;
			if (space[x_computer[p] - 1][y_computer[p]] == 0)
				d_computer[p] = 1;
			else
				if (space[x_computer[p]][y_computer[p] + 1] == 0)
					d_computer[p] = 2;
				else
					if (space[x_computer[p] + 1][y_computer[p]] == 0)
						d_computer[p] = 3;
					else
						if (space[x_computer[p]][y_computer[p] - 1] == 0)
							d_computer[p] = 4;
						else
							flag = false;
		}while (flag);
		space[i][j] = 5;
		x_computer[p] = i;
		y_computer[p] = j;
	}
	for (int i = 0; i <= 9; i++)
		f_computer[i] = true;
	puts("@:This is you.");
	puts("*:This is the computer.");
	puts("#:This is the wall.");
	puts("use 'w','a','s','d' to move.");
	puts("Use ' ' to set off the bomb.");
	puts("Press any key to comtinue.");
	system("pause");
	system("cls");
	return;
}

void chongzhi()
{
	for (int i = 0; i <= 24; i++)
		for (int j = 0; j <= 50; j++)
		{
			if (space[i][j] == 9)
				space[i][j] = 0;
		}
	return;
}

void output()
{
	for (int i = 0; i <= 24; i++)
		{
			for (int j = 0; j <= 50; j++)
				switch (space[i][j])
				{
					case 0:
						putchar(' ');
						putchar(' ');
						break;
					case 1:
						putchar('_');
						putchar('_');
						break;
					case 2:
						putchar(' ');
						putchar('|');
						break;
					case 3:
						putchar(' ');
						putchar('#');
						break;
					case 4:
						putchar(' ');
						putchar('@');
						break;
					case 5:
						putchar(' ');
						putchar('*');
						break;
					case 6:
						putchar(' ');
						putchar('%');
						break;
					case 7:
						putchar(' ');
						putchar('M');
						break;
					case 9:
						putchar(' ');
						putchar('$');
						break;
					case 64:
						putchar('%');
						putchar('@');
						break;
				}
			putchar('\n');
		}
	return;
}

int main()
{
	system("mode con cols=120 lines=30");
	int random;
	bool f_game = true;
	clock_t player_bomb = 0;
	char ch;
	srand(time(0));
	init();
	while (f_game)
	{
		output();
		chongzhi();
		clock_t timebegin = clock();
		bool flag = true;
		ch = '1';
		while (flag)
		{
			if (kbhit())
			{
				ch = getch();
			}
			else
				if ((clock() - timebegin) >= 100)
					flag = false;
		}
		switch (ch)
		{
			case 'w':
				if (space[x_player - 1][y_player] == 0)
				{
					space[x_player][y_player] = space[x_player][y_player] / 10;
					x_player--;
					space[x_player][y_player] = 4;
				}
			break;
			case 'a':
				if (space[x_player][y_player - 1] == 0)
				{
					space[x_player][y_player] = space[x_player][y_player] / 10;
					y_player--;
					space[x_player][y_player] = 4;
				}
			break;
			case 's':
				if (space[x_player + 1][y_player] == 0)
				{
					space[x_player][y_player] = space[x_player][y_player] / 10;
					x_player++;
					space[x_player][y_player] = 4;
				}
			break;
			case 'd':
				if (space[x_player][y_player + 1] == 0)
				{
					space[x_player][y_player] = space[x_player][y_player] / 10;
					y_player++;
					space[x_player][y_player] = 4;
				}
			break;
			case ' ':
				if (player_bomb == 0)
				{
					if (space[x_player][y_player] != 6 && space[x_player][y_player] != 64)
					{
						space[x_player][y_player] += 60;
						player_bomb = clock();
						x_bomb = x_player;
						y_bomb = y_player;
					}
				}
				else
				{
					boom_player();
					player_bomb = 0;
				}
			break;
		}
		for (int i = 0; i <= 9; i++)
		{
			switch (d_computer[i])
			{
				case 1:
					if (space[x_computer[i] - 1][y_computer[i]] == 0)
					{
						space[x_computer[i]][y_computer[i]] = 0;
						x_computer[i]--;
						space[x_computer[i]][y_computer[i]] = 5;
					}
					else
					{
						d_computer[i] = 3;
						if (space[x_computer[i] - 1][y_computer[i]] == 4)
							f_player = false;
						space[x_computer[i]][y_computer[i]] = 0;
						x_computer[i]++;
						space[x_computer[i]][y_computer[i]] = 5;
					}
					break;
				case 2:
					if (space[x_computer[i]][y_computer[i] + 1] == 0)
					{
						space[x_computer[i]][y_computer[i]] = 0;
						y_computer[i]++;
						space[x_computer[i]][y_computer[i]] = 5;
					}
					else
					{
						d_computer[i] = 4;
						if (space[x_computer[i]][y_computer[i] + 1] == 4)
							f_player=false;
						space[x_computer[i]][y_computer[i]] = 0;
						y_computer[i]--;
						space[x_computer[i]][y_computer[i]] = 5;
					}
					break;
				case 3:
					if (space[x_computer[i] + 1][y_computer[i]] == 0)
					{
						space[x_computer[i]][y_computer[i]] = 0;
						x_computer[i]++;
						space[x_computer[i]][y_computer[i]] = 5;
					}
					else
					{
						d_computer[i] = 1;
						if (space[x_computer[i] + 1][y_computer[i]] == 4)
							f_player = false;
						space[x_computer[i]][y_computer[i]] = 0;
						x_computer[i]--;
						space[x_computer[i]][y_computer[i]] = 5;
					}
					break;
				case 4:
					if (space[x_computer[i]][y_computer[i - 1]] == 0)
					{
						space[x_computer[i]][y_computer[i]] = 0;
						y_computer[i]--;
						space[x_computer[i]][y_computer[i]] = 5;
					}
					else
					{
						d_computer[i] = 2;
						if (space[x_computer[i]][y_computer[i] - 1] == 4)
							f_player = false;
						space[x_computer[i]][y_computer[i]] = 0;
						y_computer[i]++;
						space[x_computer[i]][y_computer[i]] = 5;
					}
					break;
			}
		}
		if (clock() - player_bomb >= 3000 && player_bomb != 0)
		{
			boom_player();
			player_bomb = 0;
		}
  		system("cls");
  		if (f_player == 0)
			f_game = false;
		flag = true;
		for (int i = 0; i <= 9; i++)
			if (f_computer[i] != 0)
				flag = false;
		if (flag)
			f_game = false;
	}
	if (f_player)
		puts("You win!");
	else
		puts("You fail.");
	puts("Thank you for your playing!");
	system("pause");
	return 0;
}
