#define _SRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#define LEFT -50
#define RIGHT 150
#define N 10

int main()
{
    srand(time(0));

    int * arr, * arr1, SIZE = 0;
    double average = 0.0;

    arr = (int*)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
    {
        arr[i] = LEFT + rand() % (RIGHT - LEFT + 1);
    }

    for (int i = 0; i < N; i++) {
        average += arr[i];
    }
    average /= N;


    for (int i = 0, j = 0; i < N; i++) {
        if (arr[i] % 2 != 0 && arr[i] > average) {
            SIZE++;
        }
    }

    arr1 = (int*)malloc(SIZE * sizeof(int));
    for (int i = 0, j = 0; i < N; i++) {
        if (arr[i] % 2 != 0 && arr[i] > average) {
            arr1[j++] = arr[i];
        }
    }


    for (int i = 0; i < N; i++)
    {
        printf("%5d", arr[i]);
    }
    printf("\n\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%5d", arr1[i]);
    }

    free(arr);
    free(arr1);

    return 0;
}
