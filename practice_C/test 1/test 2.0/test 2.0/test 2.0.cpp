#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int main()
{
    FILE* file;
    file = fopen("C:\\Users\\byako\\Desktop\\test2.0.txt", "w");
    int count = 0;

    for (int i = -45; i <= 67; i++)
    {
        if (abs(i) % 5 == 0)
        {
            fprintf(file, "%5d", i);
            count++;
            if (count % 8 == 0)
            {
                fprintf(file, "\n");
            }
        }
        if (abs(i) % 10 == 1)
        {
            printf("%d\n", i);
        }
    }

    fclose(file);
    return 0;
}

