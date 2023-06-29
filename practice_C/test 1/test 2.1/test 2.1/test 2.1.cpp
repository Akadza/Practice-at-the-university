#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <locale.h>

int main()
{ // кратность 7
    srand(time(0));

    FILE* file;
    file = fopen("C:\\Users\\byako\\Desktop\\test2.1.txt", "w");
    for (int i = 0; i < 10;)
    {
        int rand_num = (- 578 + rand() % (578 + 832 + 1));
        if (rand_num % 7 == 0)
        {
            fprintf(file, "%7d", rand_num);
            i++;
        }
    }

    fclose(file);
    return 0;
}
