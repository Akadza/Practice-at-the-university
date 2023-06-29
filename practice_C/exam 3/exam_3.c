#include "stdio.h"
#include "stdlib.h"
#define STR_LEN 1000

int lenght(const char *str);

int main() {
  FILE* file, *new_file = fopen("new_file.txt", "w");
  char letter;
  int count = 0;

  if ((file = fopen("file_for_3.txt", "r")) == NULL) {
    printf("File was not found!");
    exit(1);
  }
  while ((letter = fgetc(file)) != EOF) {
    count++;
    if (count % 5 == 0) {
      fprintf(new_file, "%c", letter);
    }
  }

  // 2
  rewind(file);
  fclose(new_file);

  char string[STR_LEN];
  int count_string = 0;
  while(!feof(file)) {
    fgets(string, STR_LEN, file);
      count_string++;
  }

  rewind(file);
  FILE *new_file1 = fopen("new_file.txt", "a");
  fprintf(new_file1, "\n");
  for (int i = 0; i < count_string; i++) {
    fgets(string, STR_LEN, file);
    for (int i = lenght(string) / 2; i < lenght(string); i++) {
      putchar(string[i]);
      fprintf(new_file1, "%c", string[i]);
    }
    printf(": %d - %d\n", lenght(string), lenght(string) / 2);
  }

  return 0;
}

int lenght(const char *str) {
  int count_letter = 0;
  while (str[count_letter] != '\0') {
    count_letter++;
  }
  return count_letter;
}
