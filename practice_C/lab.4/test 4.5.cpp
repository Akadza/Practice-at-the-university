#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
#define LEFT - 100
#define RIGHT 150

void replace_even(int* array);

int main()
{
	srand(time(0));

    int* array = (int*)malloc(sizeof(int) * SIZE);
	for (int i = 0; i < SIZE; i++)
	{
		array[i] = LEFT + rand() % (RIGHT - LEFT + 1);
	}

	for (int i = 0; i < SIZE; i++)
	{
		printf("%5d", array[i]);
	}
	
	replace_even(array);
	printf("\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%5d", array[i]);
	}

    return 0;
}

void replace_even(int* array) {
	int value = 0, count = 0;

	for (int i = 1; i < SIZE; i++)
	{
		if (abs(array[i]) % 2 == 0)
		{
			value = array[count];
			array[count] = array[i];
			array[i] = value;
			count++;
		}
	}
}