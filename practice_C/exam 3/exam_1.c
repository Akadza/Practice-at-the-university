#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#define STR_LEN 500

int lenght(const char *str);

int main() {
  srand(time(0));
  char string[STR_LEN] = "\0";
  printf("Length string = %d\n", lenght(string));

  int index_random_letter = rand() % lenght(string);
  printf("Random Symbol: ");
  putchar(string[index_random_letter]);


  return 0;
}

int lenght(const char *str) {
  int count_letter = 0;
  while (str[count_letter] != '\0') {
    count_letter++;
  }
  return count_letter;
}
