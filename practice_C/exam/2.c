#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
#define M 7
#define LEFT -20
#define RIGHT 50

int main() {
  srand(time(0));
  int array[N][M], *newArr;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      array[i][j] = LEFT + rand() % (RIGHT - LEFT + 1);
    }
  }

  double average = 0.0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      average += (double)array[i][j];
    }
  }

  average /= N * M;
  printf("\n%lf\n", average);

  int size = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if ((double)array[i][j] < average) {
        size++;
      }
    }
  }

  newArr = (int*)malloc(sizeof(int) * size);
  for (int i = 0, k = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if ((double)array[i][j] < average) {
        newArr[k] = array[i][j];
        k++;
      }
    }
  }

  free(newArr);
  return 0;
}
