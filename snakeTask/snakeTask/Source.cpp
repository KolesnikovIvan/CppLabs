#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
using namespace std;
bool gameover;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum Direction { STOP = 0, LEFT, RIGHT, DOWN, UP };
Direction dir;
void Setup()
{

	gameover = false;
	dir = STOP;
	x = width / 2-1;
	y = height / 2-1;
	fruitY = rand() % width;
	fruitX = rand() % height;
	score = 0;
}
void Draw()
{
	system("cls");
	Sleep(40);
	cout << "    press 'x' for end" << endl;
	for (int i = 0; i < width + 1; i++)
		cout << "#";
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0 || j == width - 1)
				cout << "#";
			if (i == y && j == x)
				cout << "0";
			else if (i == fruitY && j == fruitX)
				cout << "F";
			else
			{
				bool print = false;
				for (int k = 0; k < nTail; k++) //увелечение хвоста
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						print = true;
						cout << "o";
					}

				}
				if (!print)
				cout << " ";
			}
				
			
		}
		cout << endl;
	}

	for (int i = 0; i < width + 1; i++)
		cout << "#";
	cout << endl;
	cout << "score: " << score;

}

void Input()
{
	if (_kbhit()) //вводит ли пользователь что-то
	{
		switch (_getch()) 
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameover = true;
			break;
		}
	}

}

void Logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];

		prev2Y = tailY[i];
		tailY[i] = prevY;
		tailX[i] = prevX;
		prevX = prev2X;
		prevY = prev2Y;
		
	}
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	} 
	if (x > width || x < 0 || y> height || y < 0) //врезались ли в стенку
		gameover = true;
	/* чтобы проходило сквозь стены
	if (x >= width - 1)
	x = 0;
	else if (x < 0)
	x = width - 2;

	if (y >= height)
	y = 0;
	else if (y < 0)
	y = height - 1;
	
	*/
	for (int i = 0;  i < nTail; i++)
	{
		if (tailX[i] == x && tailY[i] == y)
			gameover = true;

	}

	if (x == fruitX && y == fruitY)
	{
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		nTail++;
	}
}



int main()
{
	ofstream scr("SCORE.TXT");
	Setup();
	char *name = new char[100];
	cout << "ur name "<<endl;
	cin >> name;
	char key = 'y';
		
		while (key!='n')
		{
			while (!gameover)
			{
				Draw();
				Input();
				Logic();


			}
			system("cls");
			
			cout << " Add another  [Y/n] ";
			key = _getch();
			Setup();
			scr << name << "   " << " score  :" << score << endl;
	
		}
		

	
	return 0;
}