#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count_all_letters();
int count_symbol(char letter);

int main()
{
    count_all_letters();


    return 0;
}

int count_all_letters() {
    int count = 0;
    char letter;
    FILE* file = fopen("C:\\Users\\byako\\Desktop\\for_test\\test5.3.txt", "r");
    if (file == NULL)
    {
        printf("File was not found!");
        exit(1);
    }
    while ((letter = fgetc(file)) != EOF)
    {
        count++;
    }

    fclose(file);
    return count;
}

int count_a_letter(char letter) {
    int count = 0;


    return count;
}

int count_symbol(char letter) {
    int count = 0;



    return 0;
}