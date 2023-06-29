#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int main()
{
    const int count = 4;
    const int count1 = 20;
    char name[count][count1];

    for (int i = 0; i < count; i++)
    {
        scanf("%s", name[i]);
    }
    for (int j = 0; j < count; j++)
    {
        char l = name[j][1];
        if (l == 'a' || l == 'A' || l == 'E' || l == 'e' || l == 'i'|| l == 'I' || l == 'o'|| l == 'O' || l == 'u' || l == 'U' || l == 'y' || l == 'Y')
        {
            printf("%s\n", name[j]);
        }
    }


    return 0;
}
