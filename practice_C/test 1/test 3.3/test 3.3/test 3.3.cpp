#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#define N 35

int main()
{
    srand(time(0));
    int arr[N] = {};

    for (int i = 0; i < N; i++)
    {
        arr[i] = -10000 + rand() % 20001;
    }

    for (int i = 0; i < N; i++)
    {
        printf("%7d", arr[i]);
    }
    
    printf("\n\n");
    
    int count = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        if (abs(arr[i]) % 2 == 0 && arr[i] < 0)
        {
            count++;
            if (count == 3)
            {
                printf("%d", arr[i]);
                break;
            }
        }
    }
    if (count != 3)
    {
        printf("numbers was not found!");
    }
    return 0;
}
