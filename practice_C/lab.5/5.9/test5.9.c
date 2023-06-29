#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int check(char letter);
void fill_check_file(char letter);

// создать временный файл и добавлять туда буковки (переделать тоже самое что и с массивом. только с файлом)
// AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz
int main() {
  FILE* fileopen = fopen("newFile.txt", "w");
  fclose(fileopen);

  FILE* eng_file = fopen("test5.3.txt", "r");
  FILE* file = fopen("newFile.txt", "a");
  char letter;

  if (eng_file == NULL) {
    printf("File was not found!\n");
    exit(1);
  }

  FILE* addfile = fopen("check_file.txt", "w");
  fclose(addfile);

  while ((letter = fgetc(eng_file)) != EOF) {
    if (check(letter)) {
      fill_check_file(letter);
    }
  }

  remove("check_file.txt");
  fclose(eng_file);
  return 0;
}

int check(char letter) {
  char l;
  int value = 0;
  FILE* check = fopen("check_file.txt", "r");
  while ((l = fgetc(check)) != EOF) {
    if (l == letter) {
      value++;
    }
  }
  fclose(check);
  if (value) {
    return 0;
  }
  else {
    FILE* check1 = fopen("check_file.txt", "a");
    fprintf(check, "%c", letter);
    fclose(check);
    return 1;
  }
}

void fill_check_file(char letter) {
  FILE* fillFile = fopen("newFile.txt", "a");
  fprintf(fillFile, "%c", letter);
  fclose(fillFile);
}
