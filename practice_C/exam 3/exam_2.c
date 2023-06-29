#include "stdio.h"
#include "stdlib.h"
#define LEN 7
#define STR_LEN 100

int lenght(const char *str);

int main() {

  // 1
  FILE* file;
  if ((file = fopen("file_for_2.txt", "r")) == NULL) {
    printf("File was not found!");
    exit(1);
  }

  char letter;
  while ((letter = fgetc(file)) != EOF) {
    putchar(letter);
  }

  // 2
  rewind(file);
  int count_word = 0;
  char word[STR_LEN];
  while(!feof(file)) {
    fscanf(file, "%s", word);
    if (lenght(word) < LEN) {
      count_word++;
    }
  }
  printf("\nCount words = %d\n", count_word);

  // 3
  rewind(file);
  char string[1000];
  int count_gl = 0;

  int count_string = 0;
  while(!feof(file)) {
    fgets(string, 1000, file);
      count_string++;
  }
  rewind(file);
  while(!feof(file)) {
    fgets(string, 1000, file);
    if (string[0] == 'A' || string[0] == 'a' || string[0] == 'E' || string[0] == 'e' || string[0] == 'I' || string[0] == 'i' || string[0] == 'o' || string[0] == 'O' || string[0] == 'U' || string[0] == 'u' || string[0] == 'Y' || string[0] == 'y') {
      count_gl++;
    }
  }

  printf("\nCount gl = %d\n", count_gl);
  fclose(file);
  return 0;
}

int lenght(const char *str) {
  int count_letter = 0;
  while (str[count_letter] != '\0') {
    count_letter++;
  }
  return count_letter;
}
