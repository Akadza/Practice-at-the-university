#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <locale.h>

int main()
{
    srand(time(0));

    double num;
    scanf("%lf", &num);
    
    if (num > 0.0)
    {
        do
        {
            printf("%0.2lf - 5 = ", num);
            num -= double(5);
            printf("%0.2lf\n", num);
        } while (num > 0.0);
    }
    else if (num <= 0.0)
    {
        do
        {
            double rand_num = 3 + rand() * (7 - 3) / RAND_MAX;
            printf("%0.2lf - %0.2lf = ", num, rand_num);
            num += rand_num;
            printf("%0.2lf\n", num);
        } while (num < 35.0);
    }

    return 0;
}


