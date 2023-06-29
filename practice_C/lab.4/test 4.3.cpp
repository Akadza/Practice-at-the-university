#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COL 10
#define ROW 10
#define RIGHT 250
#define LEFT -100

int line_number_summ(int ** array);
void arr_filling_summ(int ** array, int *arr_sum);

int main()
{
    srand(time(0));

    int ** array = (int**)malloc(COL * sizeof(int*));
    for (int i = 0; i < ROW; i++)
    {
        array[i] = (int*)malloc(ROW * sizeof(int));
    }
    for (int i = 0; i < COL; i++)
    {
        for (int j = 0; j < ROW; j++)
        {
            array[i][j] = LEFT + rand() % (RIGHT - LEFT + 1);
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


    int* array_summ = (int*)malloc(sizeof(int) * COL);
    arr_filling_summ(array, array_summ);
    for (int i = 0; i < COL; i++)
    {
        printf("%5d = %5d\n", i + 1, array_summ[i]);
    }
    printf("\nLine = %d", line_number_summ(array) + 1);


    for (int i = 0; i < COL; i++)
    {
        free(array[i]);
    }
    free(array);
    free(array_summ);
    return 0;
}

int line_number_summ(int ** array) {
    int line = 1, summLine = 0, summ = 0;
    // сумма первой строки
    for (int i = 0; i < ROW; i++)
    {
        if (abs(array[0][i] % 2 == 0))
        {
            summ += array[0][i];
        }
    }

    for (int i = 1; i < COL; i++)
    {
        for (int j = 0; j < ROW; j++)
        {
            if (abs(array[i][j]) % 2 == 0)
            {
                summLine += array[i][j];
            }
        }
        if (summLine < summ)
        {
            summ = summLine;
            line = i;
        }
        summLine = 0;
    }

    return line;
}

void arr_filling_summ(int ** array, int *arr_sum) {
    int summ = 0;
    for (int i = 0; i < COL; i++)
    {
        for (int j = 0; j < ROW; j++)
        {
            if (abs(array[i][j]) % 2 == 0)
            {
                summ += array[i][j];
            }
        }
        arr_sum[i] = summ;
        summ = 0;
    }
}
