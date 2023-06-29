#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
#define M 5
#define LEFT -20
#define RIGHT 50

int main() {
  srand(time(0));
  int array[N][M];
  int *newArr = (int*)malloc(sizeof(int) * N);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      array[i][j] = LEFT + rand() % (RIGHT - LEFT + 1);
    }
  }

  for (int i = 0, k = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      printf("%5d", array[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  int minValue = array[0][0];
  for (int i = 0, k = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      minValue = (minValue < array[i][j]) ? minValue : array[i][j];
    }
    newArr[k] = minValue;
    k++;
    minValue = array[i][0];
  }

  for (int i = 0; i < N; i++) {
    printf("%5d", newArr[i]);
  }

  int maxValue = newArr[0];
  for (int i = 0; i < N; i++) {
    maxValue = (maxValue > newArr[i]) ? maxValue : newArr[i];
  }
  printf("\n%5d\n", maxValue);

  free(newArr);
  return 0;
}
