#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#define LEN_STR 250


int main() {

  FILE *file;
  file = fopen("t3.txt","r");
  if (file == NULL)
  {
    printf("File was not found!");
    exit(1);
  }

  char word[LEN_STR], previousWord[LEN_STR];
  fscanf(file, "%s", previousWord);
  while (!feof(file)) {
    fscanf(file, "%s", word);
    printf("%10s %15s", "previous word", "word");
    printf("\n%10s %15s\nAvaibility: ", previousWord, word);
    for (int i = 0; i < strlen(previousWord); i++) {
      for (int j = 0; j < strlen(word); j++) {
        if (previousWord[i] == word[j]) {
          printf("%2c", previousWord[i]);
          break;
        }
      }
    }
    printf("\nPosition: ");
    int length = (strlen(previousWord) < strlen(word)) ? strlen(previousWord) : strlen(word);
    for (int i = 0; i < length; i++) {
      if (previousWord[i] == word[i]) {
        printf("%2c", previousWord[i]);
      }
    }
    printf("\n\n");
    strcpy(previousWord, word);
  }

  return 0;
}
