#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define N 8
#define RIGHT 100
#define LEFT -50

void reverse_replace(int array[N][N]);

int main()
{
	int array[N][N];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			array[i][j] = LEFT + rand() % (RIGHT - LEFT + 1);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%5d", array[i][j]);
		}
		printf("\n");
	}


	reverse_replace(array);
	printf("\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%5d", array[i][j]);
		}
		printf("\n");
	}


	return 0;
}

void reverse_replace(int array[N][N]) {
	int value;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i > j)
			{
				value = array[j + 1][i - 1];
				int check2 = array[N - 1 - j][i - 1];

				array[j + 1][i - 1] = array[N - 1 - j][i - 1];
				array[N - 1 - j][i - 1] = value;
			}
		}
	}
}
