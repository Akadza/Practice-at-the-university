#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COL 5
#define ROW 5

int find_collumnNum_max_element(int** array);
void replace_first_rand_strick(int** array);
void replace_secondaryD_collumn(int** array, int maxLineCol);

int main()
{
	srand(time(0));

    int** array = (int**)malloc(sizeof(int*) * COL);
	for (int i = 0; i < ROW; i++)
	{
		array[i] = (int*)malloc(sizeof(int) * ROW);
	}

	for (int i = 0; i < COL; i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			array[i][j] = -100 + rand() % 255;
		}
	}

	for (int i = 0; i < COL; i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			printf("%5d", array[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	replace_first_rand_strick(array);
	for (int i = 0; i < COL; i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			printf("%5d", array[i][j]);
		}
		printf("\n");
	}

	replace_secondaryD_collumn(array, find_collumnNum_max_element(array));
	printf("\n");
	for (int i = 0; i < COL; i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			printf("%5d", array[i][j]);
		}
		printf("\n");
	}

    return 0;
}

int find_collumnNum_max_element(int** array) {
	int numLine = 0, maxElement;
	// первое вхождение четного элемента
	for (int i = 0; i < COL; i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			if (abs(array[i][j]) % 2 == 0)
			{
				maxElement = array[i][j];
				numLine = j;
				break;
			}
		}
	}

	for (int i = 0; i < COL; i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			if (abs(array[i][j]) % 2 == 0 && array[i][j] > maxElement) {
				maxElement = array[i][j];
				numLine = j;
			}
		}
	}

	return numLine;
}

void replace_first_rand_strick(int** array) {
	int randStrick, value;
	randStrick = rand() % COL;
	for (int i = 0; i < COL; i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			value = array[0][j];
			array[0][j] = array[randStrick][j];
			array[randStrick][j] = value;
		}
	}
}

void replace_secondaryD_collumn(int** array, int maxLineCol) {
	int value;
	for (int i = 0; i < COL; i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			if (i + j == COL - 1)
			{
				value = array[i][j];
				array[i][j] = array[i][maxLineCol];
				array[i][maxLineCol] = value;
			}
		}
	}
}