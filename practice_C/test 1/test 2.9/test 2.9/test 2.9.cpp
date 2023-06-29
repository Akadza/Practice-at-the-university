#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[5][100];
    for (int i = 0; i < 5; i++)
    {
        scanf("%s", str[i]);
    }
    
    char str1[5*100];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                for (int l = 0; l < 5; l++)
                {
                    for (int a = 0; a < 5; a++)
                    {
                        if (i != j && i != k && j != k && i != l && i != a && l != k && a != j && k != a && a != l && j != l)
                        {
                            strcpy(str[0], str1);
                            strcpy(str[1], str1);
                            strcpy(str[2], str1);
                            strcpy(str[3], str1);
                            strcpy(str[4], str1);
                            strcat(strcat(strcat(strcat(str[0], str[1]), str[2]), str[3]), str[4]);
                            printf("\n%s", str1);
                        }
                    }
                }
            }
        }
    }


    return 0;
}

