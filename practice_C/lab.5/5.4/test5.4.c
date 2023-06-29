#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STR_LEN 50

void reverse_words();
int check_letter(char letter);
void add_letter_in_file(char letter);

int main()
{
    reverse_words();
    printf("\n");

    char word[STR_LEN];
    int count = 0;

    FILE* file = fopen("test5.3.txt", "r");
    FILE* new_file = fopen("file.txt", "w");
    fclose(new_file);

    while (!feof(file)) {
      fscanf(file, "%s", word);
      for (int i = 0; i < strlen(word) - 1; i++) {
        if (word[i] == word[i + 1] && check_letter(word[i])) {
          count++;
          add_letter_in_file(word[i]);
          break;
        }
      }
    }

    printf("\nCount = %d\n", count);
    fclose(file);
    remove("file.txt");
    return 0;
}

void reverse_words() {
    FILE* file = fopen("test5.3.txt", "r");
    if (file == NULL) {
      printf("File was not found\n");
      exit(1);
    }
    char word[STR_LEN];
    while (!feof(file)) {
        fscanf(file, "%s", word);
        int length = strlen(word);
        for (int i = 0; i < length; i++) {
            printf("%c", word[length - 1 - i]);
        }
        printf(" ");
    }

    fclose(file);
}

int check_letter(char letter) {
  int key = 0;
  FILE *check_file = fopen("file.txt", "r");

  char l;
  while ((l = fgetc(check_file)) != EOF) {
    if (letter == l) {
      key++;
      break;
    }
  }
  if (key == 1) {
    fclose(check_file);
    return 0;
  }
  else {
    fclose(check_file);
    return 1;
  }
}

void add_letter_in_file(char letter) {
  FILE *add_letter = fopen("file.txt", "a");
  fprintf(add_letter, "%c", letter);
  fclose(add_letter);
}
