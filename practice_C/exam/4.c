#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define A -20
#define B 50
#define N 5
#define M 5

int main() {
  srand(time(0));
  int array[N][M];
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++) {
      array[i][j] = A + rand() % (B - A + 1);
    }
  }

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++) {
      printf("%5d", array[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++) {
      if (i == j) {
        int value = array[i][j];
        array[i][j] = array[j][N - 1];
        array[j][N - 1] = value;
      }
    }
  }

  printf("\n");
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++) {
      printf("%5d", array[i][j]);
    }
    printf("\n");
  }

  return 0;
}
