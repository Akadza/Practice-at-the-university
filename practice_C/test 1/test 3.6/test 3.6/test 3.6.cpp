#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 14
#define COL 14

int main()
{
    srand(time(0));

    FILE* file;
    int init_array[ROW][COL];

    file = fopen("C:\\Users\\byako\\Desktop\\for_test\\test 3.6.txt", "w");
    if (file == NULL)
    {
        printf("Directory was not found");
        exit(1);
    }

    int r_num;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            init_array[i][j] = -500 + rand() % 1001;
            fprintf(file, "%6d", init_array[i][j]);
        }
        fprintf(file, "\n");
    }

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            printf("%5d", init_array[i][j]);
        }
        printf("\n");
    }

    fclose(file);

    FILE* file1;
    file1 = fopen("C:\\Users\\byako\\Desktop\\for_test\\test 3.6.txt", "r");

    int new_array[ROW][COL];
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            fscanf(file1, "%d", &new_array[i][j]);
        }
    }

    int count_values = 0, max_value = new_array[0][0];
    double average_value_5 = 0;

    // среднее значение элементов кратных 5
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (new_array[i][j] % 5 == 0)
            {
                average_value_5 += new_array[i][j];
            }
        }
    }
    average_value_5 /= ROW * COL;

    printf("\n\n");
    // максимальный элемент выше побочной диагонали
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++) // формула для побочной диагонали посмотреть i + j < N - 1/ ( выше )
        {
            if (i + j < ROW - 1)
            {
                printf("%5d", new_array[i][j]);
                max_value = max_value > new_array[i][j] ? max_value : new_array[i][j];
            }
            
        }
        printf("\n");
    }
    
    // количество элементов с последней цифрой 0
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (new_array[i][j] % 10 == 0)
            {
                count_values++;
            }
        }
    }


    printf("Average value = %lf\nMax value = %d\nCount value = %d", average_value_5, max_value, count_values);

    fclose(file1);
    return 0;
}

