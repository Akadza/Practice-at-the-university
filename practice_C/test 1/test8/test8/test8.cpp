#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    char l;
    scanf("%c", &l);
    
    switch (l)
    {
    case 'd': printf("t"); break;
    case 't': printf("d"); break;
    case 'p': printf("b"); break;
    case 'b': printf("p"); break;
    case 'g': printf("k"); break;
    case 'k': printf("g"); break;
    case 's': printf("z"); break;
    case 'z': printf("s"); break;
    case 'f': printf("v"); break;
    case 'm': printf("h"); break;
    case 'h': printf("m"); break;
    default:
        printf("Wrong!");
        break;
    }


    return 0;
}
