#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

#define X 20
#define Y 10

void clear_screen()
{
	printf("\n\033[H\033[2J");
}

void draw_field(int x, int y)
{
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			if (j == x && i == y)
			{
				printf("o");
			}
			else if (i == 0 || i == Y - 1 || j == 0 || j == X - 1)
			{
				printf("#");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}

int main(void)
{
	int x = X/2;
	int y = Y/2;
	
	int dx = 0;
	int dy = 0;
	
	
	while (1)
	{
		if (_kbhit())
		{
			char ch = _getch();
			if (ch == 'w')
			{
				dx = 0;
				dy = -1;
			}
			else if (ch == 'a')
			{
				dx = -1;
				dy = 0;
			}
			else if (ch == 'd')
			{
				dx = 1;
				dy = 0;
			}
			else if (ch == 's')
			{
				dx = 0;
				dy = 1;
			}
		}
		
		x += dx;
		y += dy;
		
		if (x < 1)
		{
			x = 1;
		}
		if (x >= X-2)
		{
			x = X-2;
		}
		if (y < 1)
		{
			y = 1;
		}
		if (y >= Y-2)
		{
			y = Y-2;
		}
		
		clear_screen();
		draw_field(x, y);
	
		Sleep(300);
	}
	
	
	return 0;
}