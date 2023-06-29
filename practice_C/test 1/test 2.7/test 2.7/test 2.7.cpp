#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double double_calculation(double, double, double);

int main()
{
    FILE* file;
    file = fopen("C:\\Users\\byako\\Desktop\\input.txt", "r");
    if (file == NULL)
    {
        printf("Wrong Name file");
        exit(1);
    }

    double a, b, c;
    fscanf(file, "%lf %lf %lf ", &a, &b, &c);
    
    if (a == 0 || (pow(b, 2) - 4 * a * c) < 0)
    {
        printf("WRONG NUMBERS!");
        return 1;
    }

    printf("%lf", double_calculation(a, b, c));
    return 0;
}

double double_calculation(double a, double b, double c) {
    double x1, x2;
    x1 = (-b + sqrt(pow(b, 2) - 4 * a * c)) / 2 * a;
    x2 = (-b - sqrt(pow(b, 2) - 4 * a * c)) / 2 * a;
    
    if (x1 > 0) {
        return x1;
    }
    if (x2 < 0) {
        return x2;
    }
}
