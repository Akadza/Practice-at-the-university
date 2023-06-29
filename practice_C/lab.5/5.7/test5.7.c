#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define STR_LEN 250
#define SIZE_GL 12

int count_gl_letters(const char * str);
int length(const char * str);
int check_letter(char letter);
void add_letter_in_file(char letter);

int main() {
  char array[STR_LEN] = "";
  strcat(array, "Lorem ipsum dolor sit amet");
  puts(array);

  printf("\nCount: %d", count_gl_letters(array));
  return 0;
}


int count_gl_letters(const char * str) {
  FILE* new_file = fopen("newFile.txt", "w");
  fclose(new_file);


  int count = 0;
  printf("Letters: ");
  char letter ;
  for (int i = 0; i < length(str); i++) {
    letter = str[i];
    if (str[i] == 'A' || str[i] == 'a' || str[i] == 'E' || str[i] == 'e' || str[i] == 'I' || str[i] == 'i' || str[i] == 'o' || str[i] == 'O' || str[i] == 'U' || str[i] == 'u' || str[i] == 'Y' || str[i] == 'y') {
      count++;
      if (check_letter(str[i])) {
        add_letter_in_file(letter);
      }
    }
  }
  return count;
}

int length(const char * str) {
  int count = 0;
  char letter = str[0];
  while (letter != '\0') {
    count++;
    letter = str[count];
  }
  return count;
}

int check_letter(char letter) {
  char l;
  int key = 0;
  FILE* letters = fopen("newFile.txt", "r");
  while ((l = fgetc(letters)) != EOF) {
    if (letter == l) {
      key++;
      break;
    }
  }
  if (key == 1) {
    fclose(letters);
    return 0;
  }
  else {
    fclose(letters);
    return 1;
  }
}

void add_letter_in_file(char letter) {
  FILE *add_letter = fopen("newFile.txt", "a");
  fprintf(add_letter, "%c", letter);
  printf("%c ", letter);
  fclose(add_letter);
}
