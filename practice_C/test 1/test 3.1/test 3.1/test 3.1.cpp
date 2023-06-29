#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

int main()
{
    srand(time(0));
    const int N = 29;
    int a[N];
    double b[N];

    for (int i = 0; i < N; i++)
    {
        a[i] = -97 + rand() % (72);
        b[i] = - 10.29 + fabs(sin(rand())) * (10.29 + 11.80);
    }

    for (int i = 0; i < N; i++)
    {
        printf("%6d", a[i]);
    }
    for (int i = 0; i < N; i++)
    {
        printf("%6.2lf", b[i]);
    }

    FILE* file;
    file = fopen("C:\\Users\\byako\\Desktop\\for_test\\3.1.txt", "w");
    for (int i = 0; i < N; i++)
    {
        fprintf(file, "array_int[%d] = %d\tarray_double[%d] = %0.2lf\n", i, a[i], i, b[i]);
    }

    return 0;
}
