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

  int indexMaxValue = 0, maxValue = array[0];
  for (int i = 0; i < N; i++) {
    if (maxValue < array[i]) {
      indexMaxValue = i;
      maxValue = array[i];
    }
  }
  printf("%5d\n\n", indexMaxValue + 1);
  int value;
  for (int i = indexMaxValue + 1; i < indexMaxValue + 1 + (N - indexMaxValue) / 2; i++) {
    value = array[i];
    array[i] = array[N - (i - indexMaxValue)];
    array[N - (i - indexMaxValue)] = value;
  }

  for (int i = 0; i < N; i++) {
    printf("%5d", array[i]);
  }
  printf("\n");

  return 0;
}
