#define _SRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define RIGHT 100
#define LEFT -50
#define N 5
#define M 5


int main()
{
	srand(time(0));

    int arr[N][M], *arr1, SIZE = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = LEFT + rand() % (RIGHT - LEFT + 1);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j < M; j += 2)
		{
			if (arr[i][j] < 0)
				SIZE++;
		}
	}

	

	arr1 = (int*)malloc(sizeof(int) * SIZE);
	for (int i = 0, k = 0; i < N; i++)
	{
		for (int j = 1; j < M; j += 2)
		{
			if (arr[i][j] < 0)
			{
				arr1[k] = arr[i][j];
				k++;
			}
		}
	}
	printf("\n\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%4d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");

	for (int i = 0; i < SIZE; i++)
	{
		printf("%5d", arr1[i]);
	}



	free(arr1);
    return 0;
}

