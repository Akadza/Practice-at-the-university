#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define STR_LEN 200

int main() {
  char str1[STR_LEN], str2[STR_LEN];
  scanf("%s %s", str1, str2);
  int min_len = (strlen(str1) > strlen(str2)) ? strlen(str2) : strlen(str1);

  strcat(str2, str1);

  puts(str1);
  puts(str2);



  return 0;
}
