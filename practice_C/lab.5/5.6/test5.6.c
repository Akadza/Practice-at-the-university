#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"
#define STR_LEN 250

int main() {
  char array[STR_LEN];
  gets(array);
  strcat(array, array);
  printf("Result = ");
  puts(array);



  return 0;
}
