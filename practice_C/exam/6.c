#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20
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

  int countValue = 0;
  for (int i = 0; i < N; i++) {
    if (array[i] % 7 == 0) {
      countValue++;
    }
  }

  for (int i = N - 1, k = 0; i >= 0; i--) {
    if (abs(array[i]) % 7 == 0) {
      int value = array[i];
      array[i] = array[N - 1 - k];
      array[N - 1 - k] = value;
      k++;
    }
  }

  for (int i = 0; i < N; i++) {
    printf("%5d", array[i]);
  }


  return 0;
}
