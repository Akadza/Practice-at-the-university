#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3
#define SIZE 150

int main() {
  char array[N][SIZE];
  for (int i = 0; i < N; i++) {
    gets(array[i]);
  }

  for (int i = 0; i < N; i++) {
    puts(array[i]);
  }


  return 0;
}
