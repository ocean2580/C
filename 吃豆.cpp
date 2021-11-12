#include<stdio>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>
#define M 50
#define N 50
void Show(char str[][M], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		puts(str[i]);
	}
}
void UpdateWithInput(char str[][M], int n)
{
	int x = 1, y = 1;
	int exitX = 10, exitY = 10;
	char input;
	while (x != exitX || y != exitY)
	{
		if (_kbhit())
		{
			input = getchar();
			if (input == 'a' && str[x][y] != '*')
			{
				str[x][y] = ' ';
				y--;
				str[x][y] = '$';
			}
			if (input == 'd' && str[x][y] != '*')
			{
				str[x][y] = ' ';
				y++;
				str[x][y] = '$';
			}
			if (input == 'w' && str[x][y] != '*')
			{
				str[x][y] = ' ';
				x--;
				str[x][y] = '$';
			}
			if (input == 's' && str[x][y] != '*')
			{
				str[x][y] = ' ';
				x++;
				str[x][y] = '$';
			}
		}
		system("cls");
		Show(str, n);
		Sleep(200);
	}
	printf("You Win!\n");
	system("PAUSE");

}
int main()
{
	char str[M][N] = {
"************",
"*$		  * ",
"* **********",
"* *   *   **",
"* * * * * **",
"* * * * *  *",
"* * * * *  *",
"* * * * ** *",
"* * * * ** *",
"* * * * ** *",
"*   *   **  ",
"************"
	};

	int n = 12;
	Show(str, n);
	UpdateWithInput(str, n);
	return 0;
};
