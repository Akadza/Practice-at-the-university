#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 7
#define RIGHT 100
#define LEFT -50

int min_value_index(int* array);
void reverse_replace_array(int* array, int minIndexValue);

int main()
{
    srand(time(0));

    int* array = (int*)malloc(sizeof(int) * SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        array[i] = LEFT + rand() % (RIGHT - LEFT + 1);
    }

    printf("%5d\n", min_value_index(array));
    for (int i = 0; i < SIZE; i++)
    {
        printf("%5d", array[i]);
    }

    printf("\n");

    reverse_replace_array(array, min_value_index(array));
    int value;
    for (int i = 0; i < SIZE; i++)
    {
        printf("%5d", array[i]);
    }


    free(array);
    return 0;
}

int min_value_index(int* array) {
    int minValueIndex = 0, minValue = array[0];
    for (int i = 0; i < SIZE; i++)
        if (minValue > array[i])
        {
            minValue = array[i];
            minValueIndex = i;
        }
    return minValueIndex;
}

void reverse_replace_array(int* array, int minIndexValue) {
    int value;
    for (int i = 0; i < minIndexValue / 2; i++)
    {
        value = array[i];
        array[i] = array[minIndexValue - 1 - i];
        array[minIndexValue - 1 - i] = value;
    }
}
