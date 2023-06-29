#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 11
#define LEFT -20
#define RIGHT 50

int main() {
  srand(time(0));
  int array[N];
  for (int i = 0; i < N; i++) {
    array[i] = LEFT + rand() % (RIGHT - LEFT + 1);
  }
  for (int i = 0; i < N; i++) {
    printf("%5d", array[i]);
  }
  printf("\n");

  int value, k = 1;
  while (k > 0) {
    k = 0;
    for (int i = N / 2 + N % 2; i < N - 1; i++) {
      if (array[i] < array[i + 1]) {
        k++;
        value = array[i];
        array[i] = array[i + 1];
        array[i + 1] = value;
      }
    }
  }

  for (int i = 0; i < N; i++) {
    printf("%5d", array[i]);
  }
  printf("\n");

  return 0;
}
