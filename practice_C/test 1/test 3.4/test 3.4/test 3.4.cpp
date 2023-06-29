#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#define N 20

int main()
{
    int arr[N];

    FILE* file;
    file = fopen("C:\\Users\\byako\\Desktop\\for_test\\input.txt", "r");
    if (file == NULL)
    {
        printf("file was not found!");
        exit(1);
    }

    for (int i = 0; i < N; i++)
    {
        fscanf(file, "%d", &arr[i]);
    }

    for (int i = 0; i < N; i++)
    {
        printf("%6d", arr[i]);
    }
    printf("\n\n");

    
    int eq, arrValue, arrFirstValue = arr[0];

    for (int i = 0; i < N; i++)
    {
        if (i == 0)
        {
            arrValue = arr[i];
            eq = (abs(arr[i + 1]) % 10) * (abs(arr[N - 1]) % 10);
            arr[i] /= eq;
            printf("%6d", eq);
        }
        else if (i == N - 1)
        {
            eq = (abs(arrValue) % 10) * (abs(arrFirstValue) % 10);
            arr[i] /= eq;
            printf("%6d", eq);
        }
        else {
            eq = (abs(arr[i + 1]) % 10) * (abs(arrValue) % 10);
            arrValue = arr[i];
            arr[i] /= eq;
            printf("%6d", eq);
        }
    }


    printf("\n\n");
    for (int i = 0; i < N; i++)
    {
        printf("%6d", arr[i]);
    }

    fclose(file);
    return 0;
}
