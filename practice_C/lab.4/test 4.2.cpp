#define _SRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N 5
#define M 10
#define LEFT -50
#define RIGHT 100

int main()
{
    srand(time(0));
    int arr[N][M], * arr1, * arr2;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            arr[i][j] = LEFT + rand() % (RIGHT - LEFT + 1);
        }
    }

    arr1 = (int*)malloc(sizeof(int) * N);

    int maxV, count;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (abs(arr[i][j] % 7 == 0)) {
          maxV = arr[i][j];
          break;
        }
      }
    }
    for (int i = 0, k = 0; i < N; i++, k++)
    
        count = 0;
        for (int j = 0; j < M; j++)
        {
            if (abs(arr[i][j]) % 7 == 0)
            {
                maxV = (maxV > arr[i][j]) ? maxV : arr[i][j];
                count++;
            }
        }
        if (count != 0)
        {
            arr1[k] = maxV;
        }
        else {
            arr1[k] = 0;
        }
    }

    int eq;
    arr2 = (int*)malloc(sizeof(int) * M);
    for (int i = 0, k = 0; i < M; i++)
    {
        eq = 1;
        for (int j = 0; j < N; j++)
        {
            if (arr[j][i] < 0 && abs(arr[j][i]) % 2 == 0)
            {
                eq *= abs(arr[j][i]);
            }
        }
        arr2[k] = eq;
        k++;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            printf("%5d", arr[i][j]);
            if (i == 0)
                for (int k = 0; k < N; k++)
                {
                    printf("%8d", arr1[k]);
                }
        printf("\n");
    }

    printf("\n\n");
    for (int i = 0; i < M; i++)
    {
        printf("%5d", arr2[i]);
    }

    free(arr1);
    free(arr2);
    return 0;
}
