#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<stdlib.h>
#include<ctime>
#include<queue>
using namespace std;

#define UP 72;
#define DOWN 80;
#define LEFT 75;
#define RIGHT 77;
struct xyVal                                            //�ṹ�� 
{
	int x;
	int y;
};
 
queue<xyVal> Que;
 
int main() {
	int level = 1;
	clock_t levelTime = 10 * 1000;
	char playSpace[22][22];
	for (int i = 1; i < 21; i++)
		for (int j = 1; j < 21; j++)
			playSpace[i][j] = 0;
	for (int i = 0; i < 22; i++)                        //ǽ 
	{
		playSpace[0][i] = '@';
		playSpace[21][i] = '@';
	}
	for (int i = 1; i < 21; i++)
	{
		playSpace[i][0] = '@';
		playSpace[i][21] = '@';
	}
	int xVal, yVal, xFood, yFood;
	srand(time(0));
	xVal = rand() % 14 + 3;
	yVal = rand() % 14 + 3;
	playSpace[xVal][yVal] = '*';
	Que.push(xyVal{ xVal, yVal });
 
 
	do {
		xFood = rand() % 20 + 1;
		yFood = rand() % 20 + 1;
	} while (xFood == xVal && yFood == yVal);
//	playSpace[xFood][yFood] = '$';                                  //��ʼ��ʳ�� 
 
	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 22; j++)
			cout << playSpace[i][j] << " ";
		cout << endl;
	}
	int move;
	int movei = rand() % 4 + 1;                                     //��ʼ������ 
	switch (movei)
	{
	case 1:
		move = 72; break;
	case 2:
		move = 75; break;
	case 3:
		move = 77; break;
	case 4:
		move = 80; break;
	}
	while (1) {
		xyVal temp;
		switch (move)
		{
		case 72:
			xVal--; break;
		case 80:
			xVal += 1; break;
		case 75:
			yVal -= 1; break;
		case 77:
			yVal += 1; break;
		}
		if (playSpace[xVal][yVal] == '@' || playSpace[xVal][yVal] == '*')
			break;
		switch (playSpace[xVal][yVal])
		{
		case 0:
			playSpace[xVal][yVal] = '*';
			Que.push(xyVal{ xVal, yVal });
 
			temp = Que.front();
			Que.pop();
			playSpace[temp.x][temp.y] = 0;
			break;
		case '$':
			playSpace[xVal][yVal] = '*';
			temp.x = xVal;
			temp.y = yVal;
			Que.push(temp);
 
			do {
				xFood = rand() % 20 + 1;
				yFood = rand() % 20 + 1;
			} while (playSpace[xFood][yFood] != 0);
			playSpace[xFood][yFood] = '$';
			break;
		}
		system("cls");
		for (int i = 0; i < 22; i++)
		{
			for (int j = 0; j < 22; j++)
				cout << playSpace[i][j] << " ";
			cout << endl;
		}
		if (clock() > levelTime)
		{
			level++;
			levelTime *= 2;
		}
		if (level > 4)
			level = 4;
		clock_t timeBegin = clock();
		char ch;
		while (1)
		{
			if (kbhit())
			{
				ch = getch();
			}
			else if (clock() - timeBegin >= 1000 / level)
				break;
		}
		if (ch == 72 || ch == 75 || ch == 77 || ch == 80)
			move = ch;
		ch = 0;
		
	}
	system("cls");
	cout << "FAILED" << endl;
	system("pause");
	return 0;
}
