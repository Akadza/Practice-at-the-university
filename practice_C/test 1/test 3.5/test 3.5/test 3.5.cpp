#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define N 25

int main()
{
    int arr[N];

    for (int i = 0; i < N; i++)
    {
        arr[i] = -99 + rand() % 199;
    }

    FILE* file;
    file = fopen("C:\\Users\\byako\\Desktop\\for_test\\test 3.5.txt", "w");

    for (int i = 0; i < N; i++)
    {
        fprintf(file, "%4d", arr[i]);
    }
    
    fclose(file);
    file = fopen("C:\\Users\\byako\\Desktop\\for_test\\test 3.5.txt", "a");

    int f_value = 0, s_value = 0;
    for (int i = 0; i < N / 2; i++) // 0 1 2 3 4 5 6 7 8 9 10
    {
        f_value += arr[i];
        s_value += arr[N - i - 1];
    }
    
    fprintf(file, "\nfirst value: %lf\nsecond value: %lf", (double)f_value / (N / 2), (double)s_value / (N / 2));
    fclose(file);
    return 0;
}
