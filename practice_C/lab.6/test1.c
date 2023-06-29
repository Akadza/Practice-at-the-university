#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define N 10
#define M 6
#define LEFT -1
#define RIGHT 1

void enterArray(int array[N][M]);
void enterArray0(int array[N][M], int num);
void fillArray(int array[N][M]);

int main() {
  int array[N][M];

  fillArray(array);
  enterArray(array);
  printf("\n");
  enterArray0(array, 0);

  return 0;
}

void fillArray(int array[N][M]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      array[i][j] = LEFT + rand() % (RIGHT - LEFT + 1);
    }
  }
}

void enterArray(int array[N][M]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      printf("%2d", array[i][j]);
    }
    printf("\n");
  }
}

void enterArray0(int array[N][M], int num) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (array[i][j] == num) {
        printf("%2d", array[i][j]);
      }
      else {
        printf("  ");
      }
    }
    printf("\n");
  }
}
