#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#define LEN_STR 500

int main()
{
    FILE* file;
    file = fopen("test5.3.txt", "r");
    if (file == NULL)
    {
        printf("File was not found!");
        exit(1);
    }

    char letter;
    while ((letter = fgetc(file)) != EOF)
    {
        putchar(letter);
    }

    rewind(file);
    printf("\n");
    // доделать
    char str[LEN_STR];
    while (!feof(file)) {
      fgets(str, LEN_STR, file);
      putchar(str[strlen(str) - 2]);
    }

    fclose(file);

    return 0;
}
