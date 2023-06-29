#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void print_console(int, int);
void print_file(int, int);

int main()
{
    print_console(-47, 67);
    print_file(-47, 67);


    return 0;
}


void print_console(int x, int y) {
    for (int i = x; i <= y; i++)
    {
        if (abs(i) % 5 == 0)
        {
            printf("%5d", i);
        }
    }
}

void print_file(int x, int y) {
    FILE* file;
    file = fopen("C:\\Users\\byako\\Desktop\\test2.6.txt", "w");
    for (int i = x; i <= y; i++)
    {
        if (abs(i) % 10 == 1)
        {
            fprintf(file, "%d\n", i);
        }
    }

    fclose(file);
}
