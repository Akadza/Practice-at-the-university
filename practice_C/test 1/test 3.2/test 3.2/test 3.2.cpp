#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

int summ(int);
int len(int);
int main()
{
    srand(time(0));
    const int N = 45;
    int array[N];
    int rand_num;

    for (int i = 0; i < N;)
    {
        rand_num = 5 + rand() % 6506;
        if (summ(rand_num) < 10)
        {
            array[i] = rand_num;
            i++;
        }
    }

    for (int i = 0; i < N; i++)
    {
        printf("%10d", array[i]);
    }

    return 0;
}

int summ(int num) {
    int res = 0;
    for (int i = len(num); i >= 0; i--)
    {
        int k = num / pow(10, i);
        res += k;
        num -= k * pow(10, i);
    }

    return res;
}


int len(int num) {
    int len = 0;
    while (num != 0)
    {
        num /= 10;
        len++;
    }

    return len;
}