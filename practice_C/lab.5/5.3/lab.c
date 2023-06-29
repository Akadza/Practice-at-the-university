#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN_STR 100

int count_string_of_file();
int count_short_words(int lengthWord);

int main()
{
    FILE* file = fopen("test5.3.txt", "a");
    if (file == NULL) {
      printf("File was not found!\n");
      exit(1);
    }
    fprintf(file, "%d\n", count_string_of_file());
    fprintf(file, "%d\n", count_short_words(10));


    fclose(file);
    return 0;
}

int count_string_of_file() {
    int countSt = 0;
    char letter;
    FILE* file = fopen("test5.3.txt", "r");
    if (file == NULL) {
      printf("File was not found!");
      exit(1);
    } // по строкам
    char str[LEN_STR];
    while (!feof(file)) {
        fgets(str, LEN_STR, file);
        countSt++;
    }

    fclose(file);
    return countSt;
}

int count_short_words(int lengthWord) {
  FILE* file = fopen("test5.3.txt", "r");
  if (file == NULL) {
    printf("File was not found!");
    exit(1);
  }
    int count = 0;
    char word[LEN_STR];
    while (!feof(file)) {
      fscanf(file, "%s", word);
      if (strlen(word) < lengthWord) {
        count++;
      }
    }

    fclose(file);
    return count;
}
