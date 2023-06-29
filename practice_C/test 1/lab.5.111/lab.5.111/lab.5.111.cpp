#include <stdio.h>
#define _CTR_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <time.h>
#define RIGHT 100
#define LEFT -50
#define N 7
#define M 5
#define SIZE 250

int main()
{
    srand(time(0));
    FILE* file;
    file = fopen("enter.txt", "w+");

    int randNum;
    for (int i = 0; i < N; i++)
    {
        randNum = LEFT + rand() % (RIGHT - LEFT + 1);
        fprintf(file, "%d ", randNum);

    }
    fclose(file);

    FILE* file1;
    file1 = fopen("enter.txt", "a");

    char strick[SIZE];
    for (int i = 0; i < M; i++)
    {
        gets(strick);
        fputs("\n", file1);
        fputs(strick, file1);
    }
    fclose(file1);

    return 0;
}
