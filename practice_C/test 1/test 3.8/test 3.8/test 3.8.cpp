#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define ROW 14
#define COL 14

double summ_arr_rand_nums(double[ROW][COL], int count); // сумма COUNT случайных чисел из массива
int count_find_neg_nums(double[ROW][COL]); // количество отрицательных элементов в побочной диагонали
double min_neg_nums(double[ROW][COL]); // минимальный положительный элемент выше главной диагонали.


int main()
{
    srand(time(0));
    double array[COL][ROW];

    for (int i = 0; i < COL; i++)
    {
        for (int j = 0; j < ROW; j++)
        {
            array[i][j] = fabs(sin(rand())) * 17 - 7;
            printf("%7.2lf", array[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");
    for (int i = 0; i < COL; i++)
    {
        for (int j = 0; j < ROW; j++)
        {
            if (i + j == COL - 1)
            {
                printf("%7.2lf", array[i][j]);
            }
        }
    }

    printf("\n\n");
    printf("%.2lf\n", summ_arr_rand_nums(array, 10));
    printf("\nCount negative numbers = %d\n", count_find_neg_nums(array));
    printf("\n\n");
    printf("\n%.2lf\n", min_neg_nums(array));

    return 0;
}

double summ_arr_rand_nums(double arr[ROW][COL], int count) {
    double sum = 0.0;
    int rand_num1, rand_num2;

    for (int i = 0; i < count; i++)
    {
        rand_num1 = rand() % ROW;
        rand_num2 = rand() % COL;
        sum += arr[rand_num1][rand_num2];
    }

    return sum;
}

int count_find_neg_nums(double arr[ROW][COL]) {
    int count = 0;

    for (int i = 0; i < COL; i++)
    {
        for (int j = 0; j < ROW; j++)
        {
            if (i + j == COL - 1 && arr[i][j] < 0)
            {
                count++;
            }
        }
    }

    return count;
}

//

double min_neg_nums(double arr[ROW][COL]) {
    double min_nums = arr[0][1];

    for (int i = 0; i < COL; i++)
    {
        for (int j = 0; j < ROW; j++)
        {
            if (j > i && arr[i][j] > 0)
            {
                min_nums = (arr[i][j] > min_nums) ? min_nums : arr[i][j];
            }
        }
    }

    return min_nums;
}