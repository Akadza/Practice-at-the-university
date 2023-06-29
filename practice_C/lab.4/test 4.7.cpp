#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 50
#define RIGHT 150
#define LEFT -50

int main()
{

    int k = 0;
    scanf("%d", &k);

    int* array = (int*)malloc(sizeof(int) * SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        array[i] = LEFT + rand() % (RIGHT - LEFT + 1);
    }

    for (int i = 0; i < SIZE; i++)
    {
        printf("%5d", array[i]);
    }

    int start = 0, end = SIZE / k, ind_max, value;
    for (int i = 0; i < k; i++)
    {
        for (int j = start; j < end; j++)
        {
            ind_max = j;
            for (int s = j + 1; s < end; s++)
            {
                if (array[s] < array[ind_max])
                {
                    ind_max = s;
                }
            }
            value = array[j];
            array[j] = array[ind_max];
            array[ind_max] = value;
        }
        start += SIZE / k;
        end += SIZE / k;
    }

    printf("\n\n");
    for (int i = 1; i < SIZE + 1; i++)
    {
        printf("%5d", array[i - 1]);
        if (i % (SIZE / k) == 0)
        {
            printf("\n");
        }
    }

    free(array);
    return 0;
}
